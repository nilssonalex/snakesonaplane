#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Pixel.h"
#include "Renderer.h"
#include "GameBoard.h"
#include "my_que.h"
#include "Input.h"
#include "Position.h"

class SnakeGame {
private:
    // Game components
    GameBoard gameBoard;
    Renderer renderer;
    InputHandler inputHandler;
    
    // LED configuration
    const uint16_t ledCount;
    const uint8_t brightness;
    
    // Snake properties
    Position snakeHeadPosition;
    MyQue snakeBody;
    Position currentFruit;
    
    // Game timing
    int prevMillis;
    int currentMillis;
    int tickTimeMillis;
    int ticks;
    int tickPerSec;
    int currentCol;
    
    // Helper method
    void updateSnakeHeadPosition(int8_t x, int8_t y);
    
public:
    // Constructor
    SnakeGame(uint16_t led_count, uint8_t bright);
    
    // Game initialization
    void setup();
    
    // Game update function
    void update();
};

#endif // SNAKE_GAME_H
