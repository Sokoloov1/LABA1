#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Структура для узла стека
struct NodeS {
    int data;
    NodeS* next;
};

// Структура для стека
struct Stack {
    NodeS* top;
};

// Функция добавления элемента в стек
void pushStack(Stack& stack, int value) {
    NodeS* newNode = new NodeS(); // Создаем новый узел
    newNode->data = value; // Присваиваем ему значение
    newNode->next = stack.top; // Новый узел указывает на текущую вершину
    stack.top = newNode; // Новый узел становится вершиной
}

// Функция удаления элемента из стека
void popStack(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Стек пуст" << endl; // Если стек пуст, выводим сообщение
        return;
    }
    NodeS* temp = stack.top; // Сохраняем текущую вершину
    stack.top = stack.top->next; // Перемещаем вершину на следующий элемент
    delete temp; // Удаляем предыдущую вершину
}

// Функция вывода содержимого стека на экран
void printStack(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Стек пуст" << endl; // Если стек пуст, выводим сообщение
        return;
    }
    NodeS* temp = stack.top; // Начинаем с вершины стека
    cout << "Элементы стека: ";
    while (temp != nullptr) {
        cout << temp->data << " "; // Выводим значение текущего узла
        temp = temp->next; // Переходим к следующему узлу
    }
    cout << endl;
}

// Функция освобождения памяти, занимаемой стеком
void freeStack(Stack& stack) {
    while (stack.top != nullptr) {
        popStack(stack); // Удаляем узлы и освобождаем память
    }
}

// Функция записи стека в файл
void writeStackToFile(const Stack& stack, const string& filename) {
    ofstream file(filename); // Открываем файл для записи

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl; // Если файл не открыт, выводим сообщение
        return;
    }

    NodeS* temp = stack.top; // Начинаем с вершины стека
    while (temp != nullptr) {
        file << temp->data << endl; // Записываем значение текущего узла в файл
        temp = temp->next; // Переходим к следующему узлу
    }

    file.close(); // Закрываем файл
}
