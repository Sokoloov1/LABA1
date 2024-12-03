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
    newNode->next = nullptr;  // указатель на следующий узел
    return newNode;
}

void enqueue(Queue& q, int item) {
    NodeQ* newNode = createNodeQ(item);
    if (q.tail == nullptr) {
        q.head = q.tail = newNode;
        return;
    }
    q.tail->next = newNode; // указатель на новый узел
    q.tail = newNode; // Обновляем указатель на хвост
}

int dequeue(Queue& q) {  //извлеч элемента
    if (q.head == nullptr) {
        cout << "The queue is empty" << endl; //Очередь пуста
        return -1;
    }
    NodeQ* temp = q.head;
    int item = q.head->data; // Извлекаем данные из первого узла
    q.head = q.head->next;
    if (q.head == nullptr) {
        q.tail = nullptr;
    }
    delete temp;
    return item;
}

void printQueue (Queue& q) {
    if (q.head == nullptr) {
        cout << "The queue is empty" << endl;
        return;
    }
    NodeQ* temp = q.head;
    cout << "Queue: ";
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
        cerr << "Error when opening a file for recording" << endl; //Ошибка при открытии файла для записи
        return;
    }

    NodeQ* temp = q.head;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}
