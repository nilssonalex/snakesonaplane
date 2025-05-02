// Renderer.cpp
#include "Renderer.h"

Renderer::Renderer(uint16_t ledCount, uint8_t brightness) :
  dataPin(dataPin),
  clockPin(clockPin),
  ledCount(ledCount),
  brightness(brightness)
{
  ledStrip = new APA102<2, 3>();  // Create dynamically with proper template args
  colors = new rgb_color[ledCount];
}

Renderer::~Renderer() {
  delete ledStrip;
  delete[] colors;
}

void Renderer::render() {
  ledStrip->write(colors, ledCount, brightness);  // Use -> for pointer access
}

void Renderer::updateColors(Pixel gameBoard[][5]) {
  Pixel currentPixel;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 5; x++) {
      currentPixel = gameBoard[y][x];
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
