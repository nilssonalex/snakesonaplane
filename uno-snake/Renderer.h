// Renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <APA102.h>
#include "Pixel.h"
#include "constants.h"

class Renderer {
  private:
    const uint8_t dataPin;
    const uint8_t clockPin;
    const uint16_t ledCount;
    const uint8_t brightness;
    
    APA102<22, 21>* ledStrip;  // Changed to pointer with template params
    rgb_color* colors;
    
  public:
    Renderer(uint16_t ledCount, uint8_t brightness);
    ~Renderer();
    
    void render();
    void updateColors(Pixel gameBoard[][C::BOARD_X]);
};

#endif
