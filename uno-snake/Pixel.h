// Pixel.h
#ifndef PIXEL_H
#define PIXEL_H

#include <Arduino.h>

struct Pixel {
  byte index, r, g, b;
  bool on;
};

#endif