// GameBoard.cpp
#include "GameBoard.h"
#include "constants.h"

GameBoard::GameBoard() {
  initialize();
}

void GameBoard::initialize() {
  // Initialize with your original setup
  // Pixel initialBoard[8][5] = {
  //   {{39, 255, 0, 0, false}, {24, 255, 0, 0, false}, {23, 255, 0, 0, false}, {8, 255, 0, 0, false}, {7, 255, 0, 0, false}},
  //   {{38, 255, 0, 0, false}, {25, 255, 0, 0, false}, {22, 255, 0, 0, false}, {9, 255, 0, 0, false}, {6, 255, 0, 0, false}},
  //   {{37, 255, 0, 0, false}, {26, 255, 0, 0, false}, {21, 255, 0, 0, false}, {10, 255, 0, 0, false}, {5, 255, 0, 0, false}},
  //   {{36, 255, 0, 0, false}, {27, 255, 0, 0, false}, {20, 255, 0, 0, false}, {11, 255, 0, 0, false}, {4, 255, 0, 0, false}},
  //   {{35, 255, 0, 0, false}, {28, 255, 0, 0, false}, {19, 255, 0, 0, false}, {12, 255, 0, 0, false}, {3, 255, 0, 0, false}},
  //   {{34, 255, 0, 0, false}, {29, 255, 0, 0, false}, {18, 255, 0, 0, false}, {13, 255, 0, 0, false}, {2, 255, 0, 0, false}},
  //   {{33, 255, 0, 0, false}, {30, 255, 0, 0, false}, {17, 255, 0, 0, false}, {14, 255, 0, 0, false}, {1, 255, 0, 0, false}},
  //   {{32, 255, 0, 0, false}, {31, 255, 0, 0, false}, {16, 255, 0, 0, false}, {15, 255, 0, 0, false}, {0, 255, 0, 0, false}},
  // };
  
  // Pixel initialBoard[4][4] = {
  //   {{3, 255, 0, 0, false}, {4, 255, 0, 0, false}, {11, 255, 0, 0, false}, {12, 255, 0, 0, false}},
  //   {{2, 255, 0, 0, false}, {5, 255, 0, 0, false}, {10, 255, 0, 0, false}, {13, 255, 0, 0, false}},
  //   {{1, 255, 0, 0, false}, {6, 255, 0, 0, false}, {9, 255, 0, 0, false}, {14, 255, 0, 0, false}},
  //   {{0, 255, 0, 0, false}, {7, 255, 0, 0, false}, {8, 255, 0, 0, false}, {15, 255, 0, 0, false}},
  // };

  // Pixel initialBoard[Constants::BOARD_Y][Constants::BOARD_X] = {
  //   {{3, 255, 0, 0, false}, {4, 255, 0, 0, false}, {11, 255, 0, 0, false}, {12, 255, 0, 0, false}},
  //   {{2, 255, 0, 0, false}, {5, 255, 0, 0, false}, {10, 255, 0, 0, false}, {13, 255, 0, 0, false}},
  //   {{1, 255, 0, 0, false}, {6, 255, 0, 0, false}, {9, 255, 0, 0, false}, {14, 255, 0, 0, false}},
  //   {{0, 255, 0, 0, false}, {7, 255, 0, 0, false}, {8, 255, 0, 0, false}, {15, 255, 0, 0, false}},
  // };

  Pixel initialBoard[C::BOARD_Y][C::BOARD_X] = {
    {{C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {123, 255, 0, 0, false}, {108, 255, 0, 0, false}, {107, 255, 0, 0, false}, {92, 255, 0, 0, false}, {91, 255, 0, 0, false}, {76, 255, 0, 0, false}, {75, 255, 0, 0, false}, {60, 255, 0, 0, false}, {59, 255, 0, 0, false}, {44, 255, 0, 0, false}, {43, 255, 0, 0, false}, {28, 255, 0, 0, false}, {27, 255, 0, 0, false}, {12, 255, 0, 0, false}, {11, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {122, 255, 0, 0, false}, {109, 255, 0, 0, false}, {106, 255, 0, 0, false}, {93, 255, 0, 0, false}, {90, 255, 0, 0, false}, {77, 255, 0, 0, false}, {74, 255, 0, 0, false}, {61, 255, 0, 0, false}, {58, 255, 0, 0, false}, {45, 255, 0, 0, false}, {42, 255, 0, 0, false}, {29, 255, 0, 0, false}, {26, 255, 0, 0, false}, {13, 255, 0, 0, false}, {10, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {121, 255, 0, 0, false}, {110, 255, 0, 0, false}, {105, 255, 0, 0, false}, {94, 255, 0, 0, false}, {89, 255, 0, 0, false}, {78, 255, 0, 0, false}, {73, 255, 0, 0, false}, {62, 255, 0, 0, false}, {57, 255, 0, 0, false}, {46, 255, 0, 0, false}, {41, 255, 0, 0, false}, {30, 255, 0, 0, false}, {25, 255, 0, 0, false}, {14, 255, 0, 0, false}, {9, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {120, 255, 0, 0, false}, {111, 255, 0, 0, false}, {104, 255, 0, 0, false}, {95, 255, 0, 0, false}, {88, 255, 0, 0, false}, {79, 255, 0, 0, false}, {72, 255, 0, 0, false}, {63, 255, 0, 0, false}, {56, 255, 0, 0, false}, {47, 255, 0, 0, false}, {40, 255, 0, 0, false}, {31, 255, 0, 0, false}, {24, 255, 0, 0, false}, {15, 255, 0, 0, false}, {8, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {119, 255, 0, 0, false}, {112, 255, 0, 0, false}, {103, 255, 0, 0, false}, {96, 255, 0, 0, false}, {87, 255, 0, 0, false}, {80, 255, 0, 0, false}, {71, 255, 0, 0, false}, {64, 255, 0, 0, false}, {55, 255, 0, 0, false}, {48, 255, 0, 0, false}, {39, 255, 0, 0, false}, {32, 255, 0, 0, false}, {23, 255, 0, 0, false}, {16, 255, 0, 0, false}, {7, 255, 0, 0, false}, {0, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {118, 255, 0, 0, false}, {113, 255, 0, 0, false}, {102, 255, 0, 0, false}, {97, 255, 0, 0, false}, {86, 255, 0, 0, false}, {81, 255, 0, 0, false}, {70, 255, 0, 0, false}, {65, 255, 0, 0, false}, {54, 255, 0, 0, false}, {49, 255, 0, 0, false}, {38, 255, 0, 0, false}, {33, 255, 0, 0, false}, {22, 255, 0, 0, false}, {17, 255, 0, 0, false}, {6, 255, 0, 0, false}, {1, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {117, 255, 0, 0, false}, {114, 255, 0, 0, false}, {101, 255, 0, 0, false}, {98, 255, 0, 0, false}, {85, 255, 0, 0, false}, {82, 255, 0, 0, false}, {69, 255, 0, 0, false}, {66, 255, 0, 0, false}, {53, 255, 0, 0, false}, {50, 255, 0, 0, false}, {37, 255, 0, 0, false}, {34, 255, 0, 0, false}, {21, 255, 0, 0, false}, {18, 255, 0, 0, false}, {5, 255, 0, 0, false}, {2, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {116, 255, 0, 0, false}, {115, 255, 0, 0, false}, {100, 255, 0, 0, false}, {99, 255, 0, 0, false}, {84, 255, 0, 0, false}, {83, 255, 0, 0, false}, {68, 255, 0, 0, false}, {67, 255, 0, 0, false}, {52, 255, 0, 0, false}, {51, 255, 0, 0, false}, {36, 255, 0, 0, false}, {35, 255, 0, 0, false}, {20, 255, 0, 0, false}, {19, 255, 0, 0, false}, {4, 255, 0, 0, false}, {3, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
    {{C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}, {C::NOT_PIXEL, 255, 0, 0, false}},
  };

  // Copy to our board
  for (int y = 0; y < C::BOARD_Y; y++) {
    for (int x = 0; x < C::BOARD_X; x++) {
      board[y][x] = initialBoard[y][x];
    }
  }
}

void GameBoard::clear() {
  for (int y = 0; y < C::BOARD_Y; y++) {
    for (int x = 0; x < C::BOARD_X; x++) {
      board[y][x].on = false;
    }
  }
}

byte GameBoard::getPixelIndex(int x, int y) {
  return board[y][x].index;
}

void GameBoard::togglePixel(int x, int y) {
  if (x >= 0 && x < C::BOARD_X && y >= 0 && y < C::BOARD_Y) {
    board[y][x].on = !board[y][x].on;
  }
}

void GameBoard::setPixel(int x, int y, bool on, byte r, byte g, byte b) {
  if (x >= 0 && x < C::BOARD_X && y >= 0 && y < C::BOARD_Y) {
    board[y][x].on = on;
    board[y][x].r = r;
    board[y][x].g = g;
    board[y][x].b = b;   
  }
}
