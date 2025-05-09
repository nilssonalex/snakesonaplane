#ifndef INPUT_H
#define INPUT_H
#include "Position.h"
#include "constants.h"

class InputHandler {
private:
    // Button states
    int oldValueUp;
    int oldValueDown;
    int oldValueRight;
    int oldValueLeft;
    
    // Pin numbers
    const int upPin;
    const int downPin;
    const int rightPin;
    const int leftPin;
    
    // Helper function to detect button presses
    bool input(int& oldValue, int newValue, int pin);

public:
    // Direction of the snake
    Position snakeDirection;

    bool didInput;
    
    // Constructor to initialize pins and default direction
    InputHandler(int up_pin = C::INPUT_PIN_UP, int down_pin = C::INPUT_PIN_DOWN, int right_pin = C::INPUT_PIN_RIGHT, int left_pin = C::INPUT_PIN_LEFT);
    
    // Initialize pins
    void setup();
    
    // Process input
    void processInput();
};

#endif // INPUT_H
