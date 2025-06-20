// Main.ino
#include "SnakeGame.h"
#include "Input.h"
#include "constants.h"

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <LEAmDNS.h>

#ifndef STASSID
#define STASSID "Machine Desk"
#define STAPSK "aaaaaaaa"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


InputHandler inputHandlerMain;

WebServer server(80);

const String startPage = "<html>\
  <head>\
    <title>Pico-W Web Server POST handling</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <p>Hello world</p>\
  </body>\
</html>";

void handleRoot() {
  server.send(200, "text/html", startPage);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleCommand() {
  if (server.hasArg("cmd")) {
    String command = server.arg("cmd");
    
    if (command == "up") {
      Serial.println("up");
      inputHandlerMain.setWebCommand(C::UP_COMMAND);
      server.send(200, "text/plain", "up");
    }
    else if (command == "down") {
      Serial.println("down");
      inputHandlerMain.setWebCommand(C::DOWN_COMMAND);
      server.send(200, "text/plain", "down");
    }
    else if (command == "left") {
      Serial.println("left");
      inputHandlerMain.setWebCommand(C::LEFT_COMMAND);
      server.send(200, "text/plain", "left");
    }
    else if (command == "right") {
      Serial.println("right");
      inputHandlerMain.setWebCommand(C::RIGHT_COMMAND);
      server.send(200, "text/plain", "right");
    }
    else {
      server.send(400, "text/plain", "Unknown command");
    }
  } else {
    server.send(400, "text/plain", "No command specified");
  }
}

// LED strip configuration
const uint16_t ledCount = 124;
const uint8_t brightness = 31;

bool isSnakeRunning = true;

// Create the snake game instance
SnakeGame snakeGame(ledCount, brightness, inputHandlerMain);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  //while (!Serial); //problem sometimes when no serial present, prod

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("picow")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/command/", handleCommand);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  
  inputHandlerMain.setup();

  // Initialize the game
  snakeGame.setup();
}

void loop() {
  // Update game state and render
  server.handleClient();

  if(inputHandlerMain.processClick()) {
    Serial.println("click");
    //isSnakeRunning = !isSnakeRunning;
  }

  if (isSnakeRunning) {
    snakeGame.update();
  }
}
