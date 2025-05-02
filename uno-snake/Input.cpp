#include "Input.h"
#include <Arduino.h>

// Constructor implementation
InputHandler::InputHandler(int yellow_pin, int blue_pin, int red_pin, int green_pin) :
    yellowPin(yellow_pin),
    bluePin(blue_pin),
    redPin(red_pin),
    greenPin(green_pin),
    oldValueYellow(LOW),
    oldValueBlue(LOW),
    oldValueRed(LOW),
    oldValueGreen(LOW)
{
    // Initialize snake direction (moving right by default)
    snakeDirection.x = 1;
    snakeDirection.y = 0;
}

// Setup method to initialize pins
void InputHandler::setup() {
    pinMode(yellowPin, INPUT);
    pinMode(bluePin, INPUT);
    pinMode(redPin, INPUT);
    pinMode(greenPin, INPUT);
}

// Process all input buttons
void InputHandler::processInput() {
    int newValueYellow = digitalRead(yellowPin);
    int newValueBlue = digitalRead(bluePin);
    int newValueRed = digitalRead(redPin);
    int newValueGreen = digitalRead(greenPin);

    if (snakeDirection.x == 0) {
        // Yellow button - move right
        if (input(oldValueYellow, newValueYellow, yellowPin)) {
            snakeDirection.x = 1;
            snakeDirection.y = 0;
        }

        // Green button - move left
        if (input(oldValueGreen, newValueGreen, greenPin)) {
            snakeDirection.x = -1;
            snakeDirection.y = 0;
        }
    } else if (snakeDirection.y == 0) {
        // Blue button - move down
        if (input(oldValueBlue, newValueBlue, bluePin)) {
            snakeDirection.y = 1;
            snakeDirection.x = 0;
        }
        
        // Red button - move up
        if (input(oldValueRed, newValueRed, redPin)) {
            snakeDirection.y = -1;
            snakeDirection.x = 0;
        }
    }
}

bool InputHandler::input(int& oldValue, int newValue, int pin) {
    newValue = digitalRead(pin);
    bool pressed = false;
    
    if (newValue != oldValue) {
        if (newValue == HIGH) {
            pressed = true;
        }
    }
    oldValue = newValue;
    return pressed;
}
