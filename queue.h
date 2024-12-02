#pragma once
#include <iostream>
using namespace std;

struct NodeQ {
    int data;
    NodeQ* next = nullptr;
};

struct Queue {
    NodeQ* head = nullptr;
    NodeQ* tail = nullptr;
};

NodeQ* createNodeQ(int val);
void enqueue(Queue& q, int item);
int dequeue(Queue& q);
void printQueue(Queue& q);
void freeQueue(Queue& q);
void writeQueueToFile(const Queue& q, const string& filename);
