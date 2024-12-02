#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Структура для узла односвязного списка
struct ListOne {
    int data;
    ListOne* next;
};

// Функция добавления элемента в начало односвязного списка
void addToHeadL1(ListOne*& head, int value) {
    ListOne* newNode = new ListOne; // Создаем новый узел
    newNode->data = value; // Присваиваем ему значение
    newNode->next = head; // Новый узел указывает на текущую голову
    head = newNode; // Новый узел становится головой
}

// Функция добавления элемента в конец односвязного списка
void addToTailL1(ListOne*& head, int value) {
    ListOne* newNode = new ListOne; // Создаем новый узел
    newNode->data = value; // Присваиваем ему значение
    newNode->next = nullptr; // Новый узел не имеет следующего узла

    if (head == nullptr) {
        head = newNode; // Если список пустой, новый узел становится головой
    } else {
        ListOne* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Ищем последний узел
        }
        temp->next = newNode; // Добавляем новый узел в конец списка
    }
}

// Функция удаления элемента из начала односвязного списка
void removeHeadL1(ListOne*& head) {
    if (head != nullptr) {
        ListOne* temp = head; // Сохраняем текущую голову
        head = head->next; // Перемещаем голову на следующий элемент
        delete temp; // Удаляем предыдущую голову
    }
}

// Функция удаления элемента из конца односвязного списка
void removeTailL1(ListOne*& head) {
    if (head == nullptr) {
        return; // Если список пустой, выходим
    }
    if (head->next == nullptr) {
        delete head; // Если в списке только один элемент, удаляем его
        head = nullptr; // Обнуляем указатель на голову
    } 
    else {
        ListOne* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next; // Ищем предпоследний узел
        }
        delete temp->next; // Удаляем последний узел
        temp->next = nullptr; // Обнуляем указатель на следующий узел предпоследнего узла
    }
}

// Функция удаления элемента по значению из односвязного списка
void removeByValueL1(ListOne*& head, int value) {
    if (head == nullptr) {
        return; // Если список пустой, выходим
    }

    if (head->data == value) {
        ListOne* temp = head; // Если удаляемый элемент - это голова
        head = head->next; // Перемещаем голову на следующий элемент
        delete temp; // Удаляем предыдущую голову
        return;
    }

    ListOne* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next; // Ищем узел, предшествующий удаляемому
    }

    if (temp->next != nullptr) {
        ListOne* toDelete = temp->next; // Сохраняем указатель на удаляемый узел
        temp->next = temp->next->next; // Обновляем указатель следующего узла
        delete toDelete; // Удаляем найденный узел
    }
}

// Функция поиска элемента по значению в односвязном списке
bool searchL1(ListOne* head, int value) {
    ListOne* temp = head; // Начинаем с головы списка
    while (temp != nullptr) {
        if (temp->data == value) { // Если найден элемент с указанным значением
            return true; // Возвращаем true
        }
        temp = temp->next; // Переходим к следующему узлу
    }
    return false; // Если элемент не найден, возвращаем false
}

// Функция вывода содержимого односвязного списка на экран
void printList1(ListOne* head) {
    ListOne* temp = head; // Начинаем с головы списка
    while (temp != nullptr) {
        cout << temp->data << " "; // Выводим значение текущего узла
        temp = temp->next; // Переходим к следующему узлу
    }
    cout << endl;
}

// Функция освобождения памяти, занимаемой односвязным списком
void freeList1(ListOne*& head) {
    while (head != nullptr) {
        removeHeadL1(head); // Удаляем узлы и освобождаем память
    }
}

// Функция записи односвязного списка в файл
void writeListToFile(ListOne* head, const string& filename) {
    ofstream file(filename); // Открываем файл для записи

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl; // Проверка на успешное открытие файла
        return;
    }

    ListOne* temp = head; // Начинаем с головы списка
    while (temp != nullptr) {
        file << temp->data << endl; // Записываем значение текущего узла в файл
        temp = temp->next; // Переходим к следующему узлу
    }

    file.close(); // Закрываем файл
}
