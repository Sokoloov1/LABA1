#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct NodeL {
    int data;
    NodeL* next;
    NodeL* previous;
};

struct DoubleList {
    NodeL* head;
    NodeL* tail;
};

void addToHeadL2(DoubleList& list, int value) {
    NodeL* newNode = new NodeL;
    newNode->data = value;
    newNode->next = list.head;
    newNode->previous = nullptr;

    if (list.head != nullptr) {
        list.head->previous = newNode;
    } 
    else {
        list.tail = newNode;
    }
    list.head = newNode;
}

void addToTailL2(DoubleList& list, int value) {
    NodeL* newNode = new NodeL;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = list.tail;

    if (list.tail != nullptr) {
        list.tail->next = newNode;
    } else {
        list.head = newNode;
    }
    list.tail = newNode;
}

void removeFromHeadL2(DoubleList& list) {
    if (list.head == nullptr) return;

    NodeL* temp = list.head;
    list.head = list.head->next;

    if (list.head != nullptr) {
        list.head->previous = nullptr;
    } else {
        list.tail = nullptr;
    }
    delete temp;
}

void removeFromTailL2(DoubleList& list) {
    if (list.tail == nullptr) return;

    NodeL* temp = list.tail;
    list.tail = list.tail->previous;

    if (list.tail != nullptr) {
        list.tail->next = nullptr;
    } else {
        list.head = nullptr;
    }
    delete temp;
}

void removeByValueL2(DoubleList& list, int value) {
    NodeL* temp = list.head;

    while (temp != nullptr) {
        if (temp->data == value) {
            if (temp->previous != nullptr) {
                temp->previous->next = temp->next;
            } 
            else {
                list.head = temp->next; // Удаляемый элемент - это голова
            }

            if (temp->next != nullptr) {
                temp->next->previous = temp->previous;
            } 
            else {
                list.tail = temp->previous; // Удаляемый элемент - это хвост
            }

            delete temp;
            return;
        }
        temp = temp->next;
    }
}

NodeL* findL2(DoubleList& list, int value) {
    NodeL* temp = list.head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void printList2(DoubleList& list) {
    NodeL* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeList2(DoubleList& list) {
    NodeL* current = list.head;
    while (current != nullptr) {
        NodeL* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    list.head = nullptr;
    list.tail = nullptr;
}

void writeDoubleListToFile(const DoubleList& list, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl;
        return;
    }

    NodeL* temp = list.head;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}
