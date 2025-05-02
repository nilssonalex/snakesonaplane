#ifndef MY_QUE_H
#define MY_QUE_H

#include <Arduino.h>
#include "Position.h"

#define BUFFER_SIZE 120

bool posEqual(Position a, Position b);

// MyQue class using Position type
class MyQue {
private:
    Position buffer[BUFFER_SIZE];
    int front, rear, count;
    
public:
    MyQue();
    void push(Position value);
    void pop();
    Position peek();
    bool empty();
    Position operator[](int index);
    int size();  // New function to return the current size
    void reset();
};

#endif
