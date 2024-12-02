#pragma once
#include <iostream>
using namespace std;

struct NodeS {
    int data;
    NodeS* next = nullptr;
};

struct Stack {
    NodeS* top = nullptr;
};

void pushStack(Stack& stack, int value);
void popStack(Stack& stack);
void printStack(Stack& stack);
void freeStack(Stack& stack);
void writeStackToFile(const Stack& stack, const string& filename);
