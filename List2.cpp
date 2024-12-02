#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Структура для узла двусвязного списка
struct NodeL {
    int data;
    NodeL* next;
    NodeL* previous;
};

// Структура для двусвязного списка
struct DoubleList {
    NodeL* head;
    NodeL* tail;
};

// Функция добавления элемента в начало двусвязного списка
void addToHeadL2(DoubleList& list, int value) {
    NodeL* newNode = new NodeL; // Создаем новый узел
    newNode->data = value; // Присваиваем ему значение
    newNode->next = list.head; // Новый узел указывает на текущую голову
    newNode->previous = nullptr; // Новый узел не имеет предыдущего узла

    if (list.head != nullptr) {
        list.head->previous = newNode; // Если список не пустой, обновляем указатель предыдущего узла головы
    } else {
        list.tail = newNode; // Если список пустой, новый узел становится и головой, и хвостом
    }
    list.head = newNode; // Новый узел становится головой
}

// Функция добавления элемента в конец двусвязного списка
void addToTailL2(DoubleList& list, int value) {
    NodeL* newNode = new NodeL; // Создаем новый узел
    newNode->data = value; // Присваиваем ему значение
    newNode->next = nullptr; // Новый узел не имеет следующего узла
    newNode->previous = list.tail; // Новый узел указывает на текущий хвост

    if (list.tail != nullptr) {
        list.tail->next = newNode; // Если список не пустой, обновляем указатель следующего узла хвоста
    } else {
        list.head = newNode; // Если список пустой, новый узел становится и головой, и хвостом
    }
    list.tail = newNode; // Новый узел становится хвостом
}

// Функция удаления элемента из начала двусвязного списка
void removeFromHeadL2(DoubleList& list) {
    if (list.head == nullptr) return; // Если список пустой, выходим

    NodeL* temp = list.head; // Сохраняем текущую голову
    list.head = list.head->next; // Перемещаем голову на следующий элемент

    if (list.head != nullptr) {
        list.head->previous = nullptr; // Обновляем указатель предыдущего узла новой головы
    } else {
        list.tail = nullptr; // Если список стал пустым, обновляем указатель на хвост
    }
    delete temp; // Удаляем предыдущую голову
}

// Функция удаления элемента из конца двусвязного списка
void removeFromTailL2(DoubleList& list) {
    if (list.tail == nullptr) return; // Если список пустой, выходим

    NodeL* temp = list.tail; // Сохраняем текущий хвост
    list.tail = list.tail->previous; // Перемещаем хвост на предыдущий элемент

    if (list.tail != nullptr) {
        list.tail->next = nullptr; // Обновляем указатель следующего узла нового хвоста
    } else {
        list.head = nullptr; // Если список стал пустым, обновляем указатель на голову
    }
    delete temp; // Удаляем предыдущий хвост
}

// Функция удаления элемента по значению из двусвязного списка
void removeByValueL2(DoubleList& list, int value) {
    NodeL* temp = list.head; // Начинаем с головы списка

    while (temp != nullptr) {
        if (temp->data == value) { // Если найден элемент с указанным значением
            if (temp->previous != nullptr) {
                temp->previous->next = temp->next; // Обновляем указатель следующего узла предыдущего узла
            } else {
                list.head = temp->next; // Удаляемый элемент - это голова
            }

            if (temp->next != nullptr) {
                temp->next->previous = temp->previous; // Обновляем указатель предыдущего узла следующего узла
            } else {
                list.tail = temp->previous; // Удаляемый элемент - это хвост
            }

            delete temp; // Удаляем найденный элемент
            return;
        }
        temp = temp->next; // Переходим к следующему узлу
    }
}

// Функция поиска элемента по значению в двусвязном списке
NodeL* findL2(DoubleList& list, int value) {
    NodeL* temp = list.head; // Начинаем с головы списка
    while (temp != nullptr) {
        if (temp->data == value) { // Если найден элемент с указанным значением
            return temp; // Возвращаем указатель на найденный элемент
        }
        temp = temp->next; // Переходим к следующему узлу
    }
    return nullptr; // Если элемент не найден, возвращаем nullptr
}

// Функция вывода содержимого двусвязного списка на экран
void printList2(DoubleList& list) {
    NodeL* temp = list.head; // Начинаем с головы списка
    while (temp != nullptr) {
        cout << temp->data << " "; // Выводим значение текущего узла
        temp = temp->next; // Переходим к следующему узлу
    }
    cout << endl;
}

// Функция освобождения памяти, занимаемой двусвязным списком
void freeList2(DoubleList& list) {
    NodeL* current = list.head; // Начинаем с головы списка
    while (current != nullptr) {
        NodeL* toDelete = current; // Сохраняем текущий узел
        current = current->next; // Переходим к следующему узлу
        delete toDelete; // Удаляем предыдущий узел
    }
    list.head = nullptr; // Обнуляем указатель на голову
    list.tail = nullptr; // Обнуляем указатель на хвост
}

// Функция записи двусвязного списка в файл
void writeDoubleListToFile(const DoubleList& list, const string& filename) {
    ofstream file(filename); // Открываем файл для записи

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl; // Проверка на успешное открытие файла
        return;
    }

    NodeL* temp = list.head; // Начинаем с головы списка
    while (temp != nullptr) {
        file << temp->data << endl; // Записываем значение текущего узла в файл
        temp = temp->next; // Переходим к следующему узлу
    }

    file.close(); // Закрываем файл
}
