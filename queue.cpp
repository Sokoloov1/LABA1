#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct NodeQ {
    int data;
    NodeQ* next;
};

struct Queue {
    NodeQ* head;
    NodeQ* tail;
};

NodeQ* createNodeQ(int val) {
    NodeQ* newNode = new NodeQ;
    newNode->data = val;
    newNode->next = nullptr;  // Инициализируем указатель на следующий узел
    return newNode;
}

void enqueue(Queue& q, int item) {
    NodeQ* newNode = createNodeQ(item);
    if (q.tail == nullptr) {
        q.head = q.tail = newNode;
        return;
    }
    q.tail->next = newNode; // Добавляем новый узел в конец очереди
    q.tail = newNode; // Обновляем указатель на последний элемент
}

int dequeue(Queue& q) {
    if (q.head == nullptr) {
        cout << "Очередь пуста" << endl;
        return -1;
    }
    NodeQ* temp = q.head;
    int item = q.head->data;
    q.head = q.head->next;
    if (q.head == nullptr) {
        q.tail = nullptr;
    }
    delete temp;
    return item;
}

void printQueue (Queue& q) {
    if (q.head == nullptr) {
        cout << "Очередь пуста" << endl;
        return;
    }
    NodeQ* temp = q.head;
    cout << "Очередь: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeQueue(Queue& q) {
    while (q.head != nullptr) {
        dequeue(q); // Удаляем узлы и освобождаем память
    }
}

void writeQueueToFile(const Queue& q, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl;
        return;
    }

    NodeQ* temp = q.head;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}
