// Renderer.cpp
#include "Renderer.h"
#include "constants.h"

Renderer::Renderer(uint16_t ledCount, uint8_t brightness) :
  dataPin(dataPin),
  clockPin(clockPin),
  ledCount(ledCount),
  brightness(brightness)
{
  ledStrip = new APA102<27, 26>();
  colors = new rgb_color[ledCount];
}

Renderer::~Renderer() {
  delete ledStrip;
  delete[] colors;
}

void Renderer::render() {
  ledStrip->write(colors, ledCount, brightness);
}

void Renderer::updateColors(Pixel gameBoard[][C::BOARD_X]) {
  Pixel currentPixel;
  for (int y = 0; y < C::BOARD_Y; y++) {
    for (int x = 0; x < C::BOARD_X; x++) {
      currentPixel = gameBoard[y][x];
      if (currentPixel.index != C::NOT_PIXEL) {
        if (currentPixel.on) {
          colors[currentPixel.index].red = currentPixel.r;
          colors[currentPixel.index].green = currentPixel.g;
          colors[currentPixel.index].blue = currentPixel.b;
        } else {
          colors[currentPixel.index].red = 0;
          colors[currentPixel.index].green = 0;
          colors[currentPixel.index].blue = 0;
        }
      }
    }
  }
}
