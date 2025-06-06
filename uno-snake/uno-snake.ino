// Main.ino
#include "SnakeGame.h"
#include "Input.h"

// LED strip configuration
const uint16_t ledCount = 124;
const uint8_t brightness = 31;

InputHandler inputHandlerMain;

bool isSnakeRunning = true;

// Create the snake game instance
SnakeGame snakeGame(ledCount, brightness);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  while (!Serial);
  
  inputHandlerMain.setup();

  // Initialize the game
  snakeGame.setup();
}

void loop() {
  // Update game state and render

  if(inputHandlerMain.processClick()) {
    Serial.println("click");
    isSnakeRunning = !isSnakeRunning;
  }

  if (isSnakeRunning) {
    snakeGame.update();
  }
}
