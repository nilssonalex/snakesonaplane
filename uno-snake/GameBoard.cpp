// GameBoard.cpp
#include "GameBoard.h"

GameBoard::GameBoard() {
  initialize();
}

void GameBoard::initialize() {
  // Initialize with your original setup
  Pixel initialBoard[8][5] = {
    {{39, 255, 0, 0, true}, {24, 255, 0, 0, false}, {23, 255, 0, 0, false}, {8, 255, 0, 0, false}, {7, 255, 0, 0, false}},
    {{38, 255, 0, 0, true}, {25, 255, 0, 0, false}, {22, 255, 0, 0, false}, {9, 255, 0, 0, false}, {6, 255, 0, 0, false}},
    {{37, 255, 0, 0, true}, {26, 255, 0, 0, false}, {21, 255, 0, 0, false}, {10, 255, 0, 0, false}, {5, 255, 0, 0, false}},
    {{36, 255, 0, 0, true}, {27, 255, 0, 0, false}, {20, 255, 0, 0, false}, {11, 255, 0, 0, false}, {4, 255, 0, 0, false}},
    {{35, 255, 0, 0, true}, {28, 255, 0, 0, false}, {19, 255, 0, 0, false}, {12, 255, 0, 0, false}, {3, 255, 0, 0, false}},
    {{34, 255, 0, 0, true}, {29, 255, 0, 0, false}, {18, 255, 0, 0, false}, {13, 255, 0, 0, false}, {2, 255, 0, 0, false}},
    {{33, 255, 0, 0, true}, {30, 255, 0, 0, false}, {17, 255, 0, 0, false}, {14, 255, 0, 0, false}, {1, 255, 0, 0, false}},
    {{32, 255, 0, 0, true}, {31, 255, 0, 0, false}, {16, 255, 0, 0, false}, {15, 255, 0, 0, false}, {0, 255, 0, 0, false}},
  };
  
  // Copy to our board
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 5; x++) {
      board[y][x] = initialBoard[y][x];
    }
  }
}

void GameBoard::clear() {
  //Serial.println("clear");
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 5; x++) {
      board[y][x].on = false;
    }
  }
}

void GameBoard::togglePixel(int x, int y) {
  if (x >= 0 && x < 5 && y >= 0 && y < 8) {
    board[y][x].on = !board[y][x].on;
  }
}

void GameBoard::setPixel(int x, int y, bool on, byte r, byte g, byte b) {
  if (x >= 0 && x < 5 && y >= 0 && y < 8) {
    board[y][x].on = on;
    board[y][x].r = r;
    board[y][x].g = g;
    board[y][x].b = b;
    
  }
    //board[0][0].on = on;
    //board[0][0].r = 0;
    //board[0][0].g = 0;
    //board[0][0].b = 255;
}
