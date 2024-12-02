#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Структура для динамического массива
struct Array {
    int* data;     // Указатель на массив данных
    int size;      // Текущий размер массива
    int capacity;  // Максимальная вместимость массива
};

// Функция инициализации массива
void initArray(Array& arr, int cap) {
    arr.data = new int[cap]; // Выделяем память для массива
    arr.size = 0;            // Инициализируем текущий размер как 0
    arr.capacity = cap;      // Устанавливаем максимальную вместимость
}

// Функция добавления элемента в конец массива
void appendArray(Array& arr, int value) {
    if (arr.size >= arr.capacity) {
        // Увеличение емкости массива, если текущий размер достиг максимальной вместимости
        arr.capacity *= 2;
        int* newData = new int[arr.capacity]; // Выделяем новый массив с увеличенной вместимостью
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i]; // Копируем данные из старого массива в новый
        }
        delete[] arr.data; // Освобождаем память, занятую старым массивом
        arr.data = newData; // Устанавливаем указатель на новый массив
    }
    arr.data[arr.size++] = value; // Добавляем элемент в конец массива и увеличиваем текущий размер
}

// Функция вставки элемента в массив по указанному индексу
void insertArray(Array& arr, int index, int value) {
    if (index < 0 || index > arr.size) {
        cerr << "Индекс за пределами допустимого" << endl; // Проверка на допустимость индекса
        return;
    }
    if (arr.size >= arr.capacity) {
        // Увеличение емкости массива, если текущий размер достиг максимальной вместимости
        arr.capacity *= 2;
        int* newData = new int[arr.capacity]; // Выделяем новый массив с увеличенной вместимостью
        for (int i = 0; i < arr.size; ++i) {
            newData[i] = arr.data[i]; // Копируем данные из старого массива в новый
        }
        delete[] arr.data; // Освобождаем память, занятую старым массивом
        arr.data = newData; // Устанавливаем указатель на новый массив
    }
    for (int i = arr.size; i > index; --i) {
        arr.data[i] = arr.data[i - 1]; // Сдвигаем элементы вправо, чтобы освободить место для нового элемента
    }
    arr.data[index] = value; // Вставляем новый элемент по указанному индексу
    arr.size++; // Увеличиваем текущий размер массива
}

// Функция получения элемента массива по указанному индексу
int getArray(const Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl; // Проверка на допустимость индекса
        return -1;
    }
    return arr.data[index]; // Возвращаем элемент по указанному индексу
}

// Функция удаления элемента массива по указанному индексу
void removeArray(Array& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl; // Проверка на допустимость индекса
        return;
    }
    for (int i = index; i < arr.size - 1; ++i) {
        arr.data[i] = arr.data[i + 1]; // Сдвигаем элементы влево, чтобы удалить элемент по указанному индексу
    }
    arr.size--; // Уменьшаем текущий размер массива
}

// Функция замены элемента массива по указанному индексу
void replaceArray(Array& arr, int index, int value) {
    if (index < 0 || index >= arr.size) {
        cerr << "Индекс за пределами допустимого" << endl; // Проверка на допустимость индекса
        return;
    }
    arr.data[index] = value; // Заменяем элемент по указанному индексу
}

// Функция получения текущего размера массива
int lengthArray(const Array& arr) {
    return arr.size; // Возвращаем текущий размер массива
}

// Функция вывода содержимого массива на экран
void displayArray(const Array& arr) {
    for (int i = 0; i < arr.size; ++i) {
        cout << arr.data[i] << " "; // Выводим каждый элемент массива
    }
    cout << endl;
}

// Функция освобождения памяти, занимаемой массивом
void freeArray(Array& arr) {
    delete[] arr.data; // Освобождаем память, занятую массивом
    arr.data = nullptr; // Устанавливаем указатель на nullptr
    arr.size = 0; // Сбрасываем текущий размер
    arr.capacity = 0; // Сбрасываем максимальную вместимость
}

// Функция записи массива в файл
void writeArrayToFile(const Array& arr, const string& filename) {
    ofstream file(filename); // Открываем файл для записи
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl; // Проверка на успешное открытие файла
        return;
    }
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl; // Записываем каждый элемент массива в файл
    }
    file.close(); // Закрываем файл
}
