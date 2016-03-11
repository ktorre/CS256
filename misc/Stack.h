#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <string>

class Stack
{
private:
    int* data;
    int allocated;
    int size;
    void grow();
public:
    Stack();
    Stack(int initialAlloc);
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& right);

    int getSize() const;

    void push(int n);
    int pop();
    int peek() const;
    std::string str() const;

    Stack& operator<<(int n);
    Stack& operator>>(int& n);
};

std::ostream& operator<<(std::ostream& os, const Stack& stack);

#endif
