// Main.ino
#include "Pixel.h"
#include "Renderer.h"
#include "GameBoard.h"
#include "my_que.h"
#include "Input.h"

// Create our game board
GameBoard gameBoard;

int currentCol = 0;
int tickPerSec = 0;

// timing variables
int prevMillis = 0;
int currentMillis = 0;
int tickTimeMillis = 1000;
int ticks = 0;

Position snakeHeadPosition = {0, 0};
MyQue snakeBody;
Position currentFruit = {255, 255};

const uint16_t ledCount = 40;
const uint8_t brightness = 31;

// Create our renderer with hardcoded pins
Renderer renderer(ledCount, brightness);

InputHandler inputHandler;

// Define which pins to use.
const uint8_t dataPin = 2;
const uint8_t clockPin = 3;

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

void setup() {
  inputHandler.setup();
  Serial.begin(115200);
  while (!Serial);
  gameBoard.clear();
  gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
  renderer.updateColors(gameBoard.getBoard());
  renderer.render();
}

void loop() {
  currentMillis = millis();
  tickPerSec++;
  
  if (currentMillis - prevMillis >= tickTimeMillis) {
    currentCol++;
    if (currentCol > 40) {
      currentCol = 0;
    }

    tickPerSec = 0;
    prevMillis = currentMillis;
    gameBoard.clear();
    
    
    updateSnakeHeadPosition(snakeHeadPosition.x + inputHandler.snakeDirection.x, snakeHeadPosition.y + inputHandler.snakeDirection.y);
    gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
    renderer.updateColors(gameBoard.getBoard());
  }

  inputHandler.processInput();
  renderer.render();
  //delay(1000);
}

void updateSnakeHeadPosition(int8_t x, int8_t y) {
  if (x == -1 || x == 5 || y == -1 || y == 8) return;

  snakeHeadPosition.x = x;
  snakeHeadPosition.y = y;
}
