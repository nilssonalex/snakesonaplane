// GameBoard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Pixel.h"
#include "constants.h"

class GameBoard {
  private:
    Pixel board[C::BOARD_Y][C::BOARD_X];
    
  public:
    GameBoard();
    
    // Initialize with default red pixels (like in your original code)
    void initialize();
    
    // Clear all pixels (set 'on' to false)
    void clear();
    
    // Toggle a specific pixel
    void togglePixel(int x, int y);

    byte getPixelIndex(int x, int y);
    
    // Set a specific pixel state
    void setPixel(int x, int y, bool on, byte r, byte g, byte b);
    
    // Get the entire board for rendering
    Pixel (*getBoard())[C::BOARD_X] { return board; }
};

#endif
