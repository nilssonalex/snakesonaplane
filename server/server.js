// server.js
const express = require('express');
const http = require('http');
const WebSocket = require('ws');
const querystring = require('querystring');

const app = express();
const port = 3000;

app.use(express.static('public'));

const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

function postCommand(cmd) {
  const postData = querystring.stringify({ cmd });

  const options = {
    hostname: 'picopcb.kontor.ikab.io',
    port: 80,
    path: '/command/',
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
      'Content-Length': Buffer.byteLength(postData),
    },
  };

  const req = http.request(options, (res) => {
    // Optionally handle response here
    let data = '';
    res.on('data', (chunk) => { data += chunk; });
    res.on('end', () => {
      console.log(`POST response: ${data}`);
    });
  });

  req.on('error', (e) => {
    console.error(`Problem with POST request: ${e.message}`);
  });

  req.write(postData);
  req.end();
}

wss.on('connection', (ws) => {
  console.log('Client connected');

  ws.on('message', (message) => {
    try {
      const data = JSON.parse(message);
      if (['up', 'down', 'left', 'right'].includes(data.cmd)) {
        console.log(`Received command: ${data.cmd}`);
        postCommand(data.cmd); // <-- Forward command as HTTP POST
        ws.send(JSON.stringify({ status: 'ok', command: data.cmd }));
      } else {
        ws.send(JSON.stringify({ status: 'error', error: 'Invalid command' }));
      }
    } catch (e) {
      ws.send(JSON.stringify({ status: 'error', error: 'Invalid JSON' }));
    }
  });

  ws.on('close', () => {
    console.log('Client disconnected');
  });
});

server.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});