#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct NodeS {
    int data;
    NodeS* next;
};

struct Stack {
    NodeS* top;
};

void pushStack(Stack& stack, int value) {
    NodeS* newNode = new NodeS(); 
    newNode->data = value;
    newNode->next = stack.top;   // Новый узел указывает на текущую вершину
    stack.top = newNode;         // Новый узел становится вершиной
}

void popStack(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Стек пуст" << endl;
        return;
    }
    NodeS* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
}

void printStack(Stack& stack) {
    if (stack.top == nullptr) {
        cout << "Стек пуст" << endl;
        return;
    }
    NodeS* temp = stack.top;
    cout << "Элементы стека: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeStack(Stack& stack) {
    while (stack.top != nullptr) {
        popStack(stack); // Удаляем узлы и освобождаем память
    }
}

void writeStackToFile(const Stack& stack, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl;
        return;
    }

    NodeS* temp = stack.top;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}
