#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct ListOne {
    int data;
    ListOne* next;
};

void addToHeadL1(ListOne*& head, int value) {
    ListOne* newNode = new ListOne;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addToTailL1(ListOne*& head, int value) {
    ListOne* newNode = new ListOne;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        ListOne* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeHeadL1(ListOne*& head) {
    if (head != nullptr) {
        ListOne* temp = head;
        head = head->next;
        delete temp;
    }
}

void removeTailL1(ListOne*& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } 
    else {
        ListOne* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

void removeByValueL1(ListOne*& head, int value) {
    if (head == nullptr) {
        return;
    }

    if (head->data == value) {
        ListOne* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListOne* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        ListOne* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

bool searchL1(ListOne* head, int value) {
    ListOne* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void printList1(ListOne* head) {
    ListOne* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeList1(ListOne*& head) {
    while (head != nullptr) {
        removeHeadL1(head);
    }
}

void writeListToFile(ListOne* head, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl;
        return;
    }

    ListOne* temp = head;
    while (temp != nullptr) {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}
