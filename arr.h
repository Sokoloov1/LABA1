#pragma once
#include <iostream>
using namespace std;

struct Array {
    int* data = nullptr;
    int size = 0;        
    int capacity = 0;    
};

void initArray(Array& arr, int cap);
void destroyArray(Array& arr);
void appendArray(Array& arr, int value);
void insertArray(Array& arr, int index, int value);
int getArray(const Array& arr, int index);
void removeArray(Array& arr, int index);
void replaceArray(Array& arr, int index, int value);
int lengthArray(const Array& arr);
void displayArray(const Array& arr);
void freeArray(Array& arr);
void writeArrayToFile(const Array& arr, const string& filename);
