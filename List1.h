#pragma once
#include <iostream>
using namespace std;
struct ListOne {
    int data;
    ListOne* next = nullptr;
};

void addToHeadL1(ListOne*& head, int value);
void addToTailL1(ListOne*& head, int value);
void removeHeadL1(ListOne*& head);
void removeTailL1(ListOne*& head);
void removeByValueL1(ListOne*& head, int value);
bool searchL1(ListOne* head, int value);
void printList1(ListOne* head);
void freeList1(ListOne*& head);
void writeListToFile(ListOne* head, const string& filename);
