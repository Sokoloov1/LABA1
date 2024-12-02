#pragma once
#include <iostream>
using namespace std;

struct NodeL {
    int data;
    NodeL* next = nullptr;
    NodeL* previous = nullptr;
};

struct DoubleList {
    NodeL* head = nullptr;
    NodeL* tail = nullptr;
};

void addToHeadL2(DoubleList& list, int value);
void addToTailL2(DoubleList& list, int value);
void removeFromHeadL2(DoubleList& list);
void removeFromTailL2(DoubleList& list);
void removeByValueL2(DoubleList& list, int value);
NodeL* findL2(DoubleList& list, int value);
void printList2(DoubleList& list);
void freeList2(DoubleList& list);
void writeDoubleListToFile(const DoubleList& list, const string& filename);
