#include "SnakeGame.h"
#include <Arduino.h>
#include "constants.h"

bool gameBoardState[C::BOARD_Y][C::BOARD_X] = {
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
  {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
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
    tickTimeMillis(250),
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
    // snakeBody.push({3, 1});
    gameBoardState[1][1] = true;
    gameBoardState[1][2] = true;
    // gameBoardState[1][3] = true;

    randomSeed(analogRead(A0));

    placeFruit();

    // Initialize input handler
    inputHandler.setup();
    
    // Clear the game board
    gameBoard.clear();
    
    // Place the snake head
    //snakeHeadPosition = {0, 0};
    //gameBoard.setPixel(snakeHeadPosition.x, snakeHeadPosition.y, true, 0, 255, 0);
    logGameBoardState();
    // Update the renderer
    renderer.updateColors(gameBoard.getBoard());
    renderer.render();
}

void SnakeGame::logGameBoardState() {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      if (gameBoardState[y][x]) {
        Serial.print("x");
      } else {
        Serial.print("o");
      }
    }
    Serial.println("");
    Serial.println("-------------------");
  }
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
        //tickPerSec = 0;
        prevMillis = currentMillis;
        gameBoard.clear();

        Position currentSnakeHeadPosition = getSnakeHeadPosition();
        
        Serial.print("varv");
        Serial.println(tickPerSec);
        //logGameBoardState();

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
        inputHandler.didInput = false;
    }
    
    inputHandler.processInput();
    renderer.render();
}

// Helper method to update snake head position with boundary checking
void SnakeGame::updateSnakeHeadPosition(uint8_t x, uint8_t y) {
  if (isDead({x, y})) {
    //Serial.println("so dead");
    reset();
    return;
  }
  //if (x == -1 || x == 4 || y == -1 || y == 4) return;
  Position currentSnakeHeadPosition = getSnakeHeadPosition();
  if (posEqual({x, y}, currentFruit)) {
    placeFruit();
  } else {
    gameBoardState[snakeBody[0].y][snakeBody[0].x] = false;
    snakeBody.pop();
  }
  gameBoardState[y][x] = true;
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
        p.x = random(1, 15);
        p.y = random(1, 8);
    } while (isExcluded(p.x, p.y));  // Retry if excluded
    return p;
}

bool SnakeGame::isDead(Position pos) {
  if (gameBoardState[pos.y][pos.x]) {
    Serial.println("collission with self");
    return true;
  }
  if(gameBoard.getPixelIndex(pos.x, pos.y) == C::NOT_PIXEL) {
    Serial.println("collission with wall");
    return true;
  }

  return false;
}

void SnakeGame::reset() {
  //resetta gameBoardState
  for (byte x = 0; x < C::BOARD_X; x++) {
    for (byte y = 0; y < C::BOARD_Y; y++) {
      gameBoardState[y][x] = false;
    }
  }
  snakeBody.reset();
  //sätt tillbaka ormen till start, och gameBoardState
  snakeBody.push({1, 1});
  snakeBody.push({2, 1});
  gameBoardState[1][1] = true;
  gameBoardState[1][2] = true;

  //sätt rörelsevektorn
  inputHandler.snakeDirection.x = 1;
  inputHandler.snakeDirection.y = 0;

  //ny frukt
  placeFruit();
}

Position SnakeGame::getSnakeHeadPosition() {
  return snakeBody[snakeBody.size()-1];
}