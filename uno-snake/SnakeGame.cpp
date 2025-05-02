#include "SnakeGame.h"
#include <Arduino.h>

bool gameBoardState[8][5] = {
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false},
  {false, false, false, false, false}
};

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
    snakeBody.push({1, 1});
    snakeBody.push({2, 1});
    snakeBody.push({3, 1});
    gameBoardState[1][1] = true;
    gameBoardState[1][2] = true;
    gameBoardState[1][3] = true;

    randomSeed(analogRead(A0));

    placeFruit();

    // Initialize input handler
    inputHandler.setup();
    
    // Clear the game board
    gameBoard.clear();
    
    // Place the snake head
    //snakeHeadPosition = {0, 0};
    //gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
    
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

        Position currentSnakeHeadPosition = getSnakeHeadPosition();
        
        updateSnakeHeadPosition(
            currentSnakeHeadPosition.x + inputHandler.snakeDirection.x, 
            currentSnakeHeadPosition.y + inputHandler.snakeDirection.y
        );
        
        gameBoard.setPixel(currentFruit.x, currentFruit.y, true, 255, 0, 0);
        
        for (int i = 0; i < snakeBody.size(); i++) {
            if (i == snakeBody.size() - 1) {
                gameBoard.setPixel(snakeBody[i].x, snakeBody[i].y, true, 0, 255, 0);

            } else {
                gameBoard.setPixel(snakeBody[i].x, snakeBody[i].y, true, 0, 210, 25);
            }
        }

        //gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
        renderer.updateColors(gameBoard.getBoard());
    }
    
    inputHandler.processInput();
    renderer.render();
}

// Helper method to update snake head position with boundary checking
void SnakeGame::updateSnakeHeadPosition(int8_t x, int8_t y) {
  if (isDead({x, y})) {
    //Serial.println("so dead");
    reset();
    return;
  }
  if (x == -1 || x == 8 || y == -1 || y == 8) return;
  Position currentSnakeHeadPosition = getSnakeHeadPosition();
  if (posEqual({x, y}, currentFruit)) {
    placeFruit();
  } else {
    gameBoardState[snakeBody[0].x][snakeBody[0].y] = false;
    snakeBody.pop();
  }
  gameBoardState[x][y] = true;
  snakeBody.push({x, y});
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
        p.x = random(0, 5);
        p.y = random(0, 8);
    } while (isExcluded(p.x, p.y));  // Retry if excluded
    return p;
}

bool SnakeGame::isDead(Position pos) {
  if (gameBoardState[pos.y][pos.x]) {
    return true;
  }
  if (pos.x < 0 || pos.x > 4) {
    Serial.println("out of bounds x");

    return true;
  }
  if (pos.y < 0 || pos.y > 7) {
    Serial.println("out of bounds y");

    return true;
  }
  return false;
}

void SnakeGame::reset() {
  //resetta gameBoardState
  for (byte x = 0; x < 5; x++) {
    for (byte y = 0; y < 8; y++) {
      gameBoardState[y][x] = false;
    }
  }
  snakeBody.reset();
  //sätt tillbaka ormen till start, och gameBoardState
  snakeBody.push({1, 1});
  snakeBody.push({2, 1});
  snakeBody.push({3, 1});
  gameBoardState[1][1] = true;
  gameBoardState[2][1] = true;
  gameBoardState[3][1] = true;

  //sätt rörelsevektorn
  inputHandler.snakeDirection.x = 1;
  inputHandler.snakeDirection.y = 0;

  //ny frukt
  placeFruit();
}

Position SnakeGame::getSnakeHeadPosition() {
  return snakeBody[snakeBody.size()-1];
}