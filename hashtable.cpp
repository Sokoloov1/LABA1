#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int TABLE_SIZE = 10; // Размер хеш-таблицы

// Структура для хранения ключ-значение и указателя на следующий элемент
struct HashTable {
    string key;
    string value;
    HashTable* next; // Указатель на следующий элемент в цепочке
};

// Хеш-функция
int hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += ch;
    }
    return hash % TABLE_SIZE;
}

// Добавление элемента (ключ-значение)
void insertTable(HashTable* table[], const string& key, const string& value) {
    int index = hashFunction(key);
    HashTable* newNode = new HashTable{key, value, nullptr};

    // Проверяем, есть ли уже элементы по этому индексу
    if (table[index] == nullptr) {
        table[index] = newNode; // Если нет, добавляем как первый элемент
    } else {
        // Если есть, ищем, существует ли уже элемент с таким ключом
        HashTable* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                // Обновляем значение, если ключ найден
                temp->value = value;
                delete newNode; // Удаляем ненужный новый узел
                return;
            }
            if (temp->next == nullptr) {
                break; // Найдена последняя нода
            }
            temp = temp->next;
        }
        // Добавляем новый узел в конец списка
        temp->next = newNode;
    }
}

// Получение значения по ключу
string getValueTable(HashTable* table[], const string& key) {
    int index = hashFunction(key);
    HashTable* temp = table[index];
    
    while (temp != nullptr) {
        if (temp->key == key) {
            return temp->value; // Возвращаем значение, если ключ найден
        }
        temp = temp->next;
    }
    return "Key not found"; // Если ключ не найден
}

// Удаление элемента по ключу
void removeValueTable(HashTable* table[], const string& key) {
    int index = hashFunction(key);
    HashTable* temp = table[index];
    HashTable* prev = nullptr;

    while (temp != nullptr) {
        if (temp->key == key) {
            if (prev == nullptr) {
                // Удаляем первый элемент в цепочке
                table[index] = temp->next;
            } else {
                // Удаляем элемент в середине или конце цепочки
                prev->next = temp->next;
            }
            delete temp; // Освобождаем память
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Key not found" << endl; // Если ключ не найден
}

// Печать всей хеш-таблицы для проверки
void printTable(HashTable* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        HashTable* temp = table[i];
        while (temp != nullptr) {
            cout << "[" << temp->key << ": " << temp->value << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Очистка памяти, освобождение всех узлов
void freeTable(HashTable* table[]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashTable* temp = table[i];
        while (temp != nullptr) {
            HashTable* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
}

void writeHashTableToFile(HashTable* table[], const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла для записи" << endl;
        return;
    }

    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashTable* temp = table[i];
        while (temp != nullptr) {
            file << "[" << temp->key << ": " << temp->value << "] ";
            temp = temp->next;
        }
        file << endl;
    }

    file.close();
}
