#include "my_que.h"

// Constructor
MyQue::MyQue() : front(0), rear(0), count(0) {}

// Push method
void MyQue::push(Position value) {
    if (count == BUFFER_SIZE) {
        Serial.println("Buffer Full");
        return;
    }
    buffer[rear] = value;
    rear = (rear + 1) % BUFFER_SIZE;
    count++;
}

// Pop method
void MyQue::pop() {
    if (count == 0) {
        Serial.println("Buffer Empty");
        return;
    }
    front = (front + 1) % BUFFER_SIZE;
    count--;
}

// Peek method
Position MyQue::peek() {
    if (count == 0) {
        Serial.println("Queue Empty");
        return Position();  // Return default Position (x = 0, y = 0)
    }
    return buffer[front];
}

// Empty check
bool MyQue::empty() {
    return count == 0;
}

// Indexing operator
Position MyQue::operator[](int index) {
    if (index < 0 || index >= count) {
        Serial.println("Index out of bounds!");
        return Position();  // Return default Position (x = 0, y = 0)
    }
    return buffer[(front + index) % BUFFER_SIZE];
}

// Size function
int MyQue::size() {
    return count;
}

void MyQue::reset() {
  front = 0;
  rear = 0;
  count = 0;
}

bool posEqual(Position a, Position b) {
    return (a.x == b.x) && (a.y == b.y);
}
