#include "Input.h"
#include <Arduino.h>

// Constructor implementation
InputHandler::InputHandler(int up_pin, int down_pin, int right_pin, int left_pin, int click_pin) :
    upPin(up_pin),
    downPin(down_pin),
    rightPin(right_pin),
    leftPin(left_pin),
    clickPin(click_pin),
    oldValueUp(LOW),
    oldValueDown(LOW),
    oldValueRight(LOW),
    oldValueLeft(LOW),
    oldValueClick(LOW)
{
    // Initialize snake direction (moving right by default)
    snakeDirection.x = 1;
    snakeDirection.y = 0;
}

// Setup method to initialize pins
void InputHandler::setup() {
    pinMode(upPin, INPUT);
    pinMode(downPin, INPUT);
    pinMode(rightPin, INPUT);
    pinMode(leftPin, INPUT);
    pinMode(clickPin, INPUT);   
}

// Process all input buttons
void InputHandler::processInput() {
    if (didInput) return;

    if (snakeDirection.x == 0) {
        int newValueRight = webCommand == C::RIGHT_COMMAND;//digitalRead(rightPin);
        int newValueLeft = webCommand == C::LEFT_COMMAND;//digitalRead(leftPin);
    
        // move right
        if (input(oldValueRight, newValueRight, rightPin)) {
            snakeDirection.x = 1;
            snakeDirection.y = 0;
            didInput = true;
        }

        // move left
        if (input(oldValueLeft, newValueLeft, leftPin)) {
            snakeDirection.x = -1;
            snakeDirection.y = 0;
            didInput = true;
        }
    } else if (snakeDirection.y == 0) {
        //int newValueDown = digitalRead(downPin);
        
        int newValueDown = webCommand == C::DOWN_COMMAND;      
        int newValueUp = webCommand == C::UP_COMMAND;//digitalRead(upPin);

        // move down
        if (input(oldValueDown, newValueDown, downPin)) {
            snakeDirection.y = 1;
            snakeDirection.x = 0;
            didInput = true;
        }
        
        // move up
        if (input(oldValueUp, newValueUp, upPin)) {
            snakeDirection.y = -1;
            snakeDirection.x = 0;
            didInput = true;
        }
    }
}

void InputHandler::flushWebCommand() {
    webCommand = 'n';
}

void InputHandler::setWebCommand(byte command) {
    Serial.println("setweb");
    webCommand = command;
    Serial.print("aftersetweb: ");
    Serial.println(webCommand);
}

void InputHandler::printStatus() {
    Serial.print("status: ");
    Serial.println(webCommand);
}

bool InputHandler::processClick() {
    int newValueClick = digitalRead(clickPin);

    if (input(oldValueClick, newValueClick, clickPin)) {
        return true;
    }

    return false;
}

bool InputHandler::input(int& oldValue, int newValue, int pin) {
    //newValue = digitalRead(pin);
    bool pressed = false;
    
    if (newValue != oldValue) {
        if (newValue == HIGH) {
            pressed = true;
        }
    }
    oldValue = newValue;
    return pressed;
}
