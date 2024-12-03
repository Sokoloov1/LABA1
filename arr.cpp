#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct Array {
    int* data;         // Указатель на массив
    int size;        
    int capacity;    // Максимальная вместимость массива
};

void initArray(Array& arr, int cap) {
    arr.data = new int[cap]; // Выделение памяти под массив
    arr.size = 0;             
    arr.capacity = cap;       // Задание начальной вместимости
}

void appendArray(Array& arr, int value) {
    if (arr.size >= arr.capacity) {
        // Увеличение емкости массива
        arr.capacity *= 2;
        int* newData = new int[arr.capacity]; // Выдел памяти для увеличенного массива
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    arr.data[arr.size++] = value;
}

void insertArray(Array& arr, int index, int value) {
    if (index < 0 || index > arr.size) {
        cerr << "The index is beyond the acceptable range" << endl; //Индекс за пределами допустимого
        return;
    }
    if (arr.size >= arr.capacity) {
        arr.capacity *= 2;
        int* newData = new int[arr.capacity];
        for (int i = 0; i < arr.size; ++i) { // Копирование старых данных

            newData[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newData;
    }
    for (int i = arr.size; i > index; --i) {//Сдвиг вправо для освобождения места
        arr.data[i] = arr.data[i - 1];
    }
    arr.data[index] = value;
    arr.size++;
}

int getArray(const Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "The index is beyond the acceptable range" << endl;
        return -1;
    }
    return arr.data[index];
}

void removeArray(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "The index is beyond the acceptable range" << endl;
        return;
    }
    for (int i = index; i < arr.size - 1; ++i) {// Сдвиг элем влево, заполн пробел
        arr.data[i] = arr.data[i + 1];
    }
    arr.size--;
}
// замен элемента по индексу
void replaceArray(Array& arr, int index, int value) {
    if (index < 0 || index >= arr.size) {
        cerr << "The index is beyond the acceptable range" << endl;
        return;
    }
    arr.data[index] = value;
}

int lengthArray(const Array& arr) {
    return arr.size;
}
void displayArray(const Array& arr) {
    
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

void freeArray(Array& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

void writeArrayToFile(const Array& arr, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error when opening a file for recording" << endl; //Ошибка при открытии файла для записи
        return;
    }
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl;
    }
    file.close();
}
