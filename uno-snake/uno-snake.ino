// Main.ino
#include "SnakeGame.h"

// LED strip configuration
const uint16_t ledCount = 124;
const uint8_t brightness = 5;

// Create the snake game instance
SnakeGame snakeGame(ledCount, brightness);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  while (!Serial);
  
  // Initialize the game
  snakeGame.setup();
}

void loop() {
  // Update game state and render
  snakeGame.update();
}
