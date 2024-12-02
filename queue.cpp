#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Структура для узла очереди
struct NodeQ {
    int data;
    NodeQ* next;
};

// Структура для очереди
struct Queue {
    NodeQ* head;
    NodeQ* tail;
};

// Функция создания нового узла очереди
NodeQ* createNodeQ(int val) {
    NodeQ* newNode = new NodeQ; // Выделяем память для нового узла
    newNode->data = val; // Присваиваем ему значение
    newNode->next = nullptr;  // Инициализируем указатель на следующий узел как nullptr
    return newNode;
}

// Функция добавления элемента в очередь
void enqueue(Queue& q, int item) {
    NodeQ* newNode = createNodeQ(item); // Создаем новый узел
    if (q.tail == nullptr) {
        q.head = q.tail = newNode; // Если очередь пуста, новый узел становится и головой, и хвостом
        return;
    }
    q.tail->next = newNode; // Добавляем новый узел в конец очереди
    q.tail = newNode; // Обновляем указатель на последний элемент
}

// Функция удаления элемента из очереди
int dequeue(Queue& q) {
    if (q.head == nullptr) {
        cout << "Очередь пуста" << endl; // Если очередь пуста, выводим сообщение
        return -1;
    }
    NodeQ* temp = q.head; // Сохраняем текущую голову
    int item = q.head->data; // Сохраняем значение головы
    q.head = q.head->next; // Перемещаем голову на следующий элемент
    if (q.head == nullptr) {
        q.tail = nullptr; // Если очередь стала пустой, обновляем указатель на хвост
    }
    delete temp; // Удаляем предыдущую голову
    return item; // Возвращаем значение удаленного элемента
}

// Функция вывода содержимого очереди на экран
void printQueue(Queue& q) {
    if (q.head == nullptr) {
        cout << "Очередь пуста" << endl; // Если очередь пуста, выводим сообщение
        return;
    }
    NodeQ* temp = q.head; // Начинаем с головы очереди
    cout << "Очередь: ";
    while (temp != nullptr) {
        cout << temp->data << " "; // Выводим значение текущего узла
        temp = temp->next; // Переходим к следующему узлу
    }
    cout << endl;
}

// Функция освобождения памяти, занимаемой очередью
void freeQueue(Queue& q) {
    while (q.head != nullptr) {
        dequeue(q); // Удаляем узлы и освобождаем память
    }
}

// Функция записи очереди в файл
void writeQueueToFile(const Queue& q, const string& filename) {
    ofstream file(filename); // Открываем файл для записи
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl; // Если файл не открыт, выводим сообщение
        return;
    }

    NodeQ* temp = q.head; // Начинаем с головы очереди
    while (temp != nullptr) {
        file << temp->data << endl; // Записываем значение текущего узла в файл
        temp = temp->next; // Переходим к следующему узлу
    }

    file.close(); // Закрываем файл
}
