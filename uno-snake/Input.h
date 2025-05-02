#ifndef INPUT_H
#define INPUT_H
#include "Position.h"

class InputHandler {
private:
    // Button states
    int oldValueYellow;
    int oldValueBlue;
    int oldValueRed;
    int oldValueGreen;
    
    // Pin numbers
    const int yellowPin;
    const int bluePin;
    const int redPin;
    const int greenPin;
    
    // Helper function to detect button presses
    bool input(int& oldValue, int newValue, int pin);

public:
    // Direction of the snake
    Position snakeDirection;
    
    // Constructor to initialize pins and default direction
    InputHandler(int yellow_pin = 7, int blue_pin = 6, int red_pin = 5, int green_pin = 4);
    
    // Initialize pins
    void setup();
    
    // Process input
    void processInput();
};

#endif // INPUT_H
