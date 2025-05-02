#include "SnakeGame.h"
#include <Arduino.h>

// Constructor implementation
SnakeGame::SnakeGame(uint16_t led_count, uint8_t bright) :
    ledCount(led_count),
    brightness(bright),
    renderer(led_count, bright),
    snakeHeadPosition({0, 0}),
    currentFruit({255, 255}),
    prevMillis(0),
    currentMillis(0),
    tickTimeMillis(1000),
    ticks(0),
    tickPerSec(0),
    currentCol(0)
{
    // Constructor initializes variables with initialization list
}

// Game initialization
void SnakeGame::setup() {
    // Initialize input handler
    inputHandler.setup();
    
    // Clear the game board
    gameBoard.clear();
    
    // Place the snake head
    snakeHeadPosition = {0, 0};
    gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
    
    // Update the renderer
    renderer.updateColors(gameBoard.getBoard());
    renderer.render();
}

// Game update function
void SnakeGame::update() {
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
        
        updateSnakeHeadPosition(
            snakeHeadPosition.x + inputHandler.snakeDirection.x, 
            snakeHeadPosition.y + inputHandler.snakeDirection.y
        );
        
        gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
        renderer.updateColors(gameBoard.getBoard());
    }
    
    inputHandler.processInput();
    renderer.render();
}

// Helper method to update snake head position with boundary checking
void SnakeGame::updateSnakeHeadPosition(int8_t x, int8_t y) {
    if (x == -1 || x == 5 || y == -1 || y == 8) return;
    snakeHeadPosition.x = x;
    snakeHeadPosition.y = y;
}

void SnakeGame::placeFruit() {
  currentFruit = getRandomPair();
}

bool SnakeGame::isExcluded(uint8_t x, uint8_t y) {
    for (int i = 0; i < snakeBody.size(); i++) {
        if (snakeBody[i].x == x && snakeBody[i].y == y) {
            return true;  // Found in exclusion list
        }
    }
    return false;
}

Position SnakeGame::getRandomPair() {
    Position p;
    do {
        p.x = random(0, 8);
        p.y = random(0, 8);
    } while (isExcluded(p.x, p.y));  // Retry if excluded
    return p;
}