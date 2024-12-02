#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "hashtable.h"
#include "List1.h"
#include "List2.h"
#include "massive.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"


using namespace std;

void hashtableCmds(HashTable* hashTable[]) {
    string command;
    string key, value;
    cout << "Введите команду (INSERT, GET, REMOVE, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "INSERT") {
            if (ss >> key >> value && !key.empty() && !value.empty()) {
                insertTable(hashTable, key, value);
                writeHashTableToFile(hashTable, "hashtable.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: INSERT <ключ> <значение>" << endl;
            }
        } 
        else if (action == "GET") {
            if (ss >> key && !key.empty()) {
                cout << "Значение: " << getValueTable(hashTable, key) << endl;
            } else {
                cout << "> Неверный ввод. Необходимо ввести: GET <ключ>" << endl;
            }
        }
        else if (action == "REMOVE") {
            if (ss >> key && !key.empty()) {
                removeValueTable(hashTable, key);
                writeHashTableToFile(hashTable, "hashtable.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: REMOVE <ключ>" << endl;
            }
        } 
        else if (action == "PRINT") {
            printTable(hashTable);
        }
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: INSERT, GET, REMOVE, PRINT, EXIT." << endl;
        }
    }
}

void list1Cmds (ListOne*& head) {
    string command;
    int value;

    cout << "Введите команду (ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, SEARCH, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "ADDHEAD") {
            ss >> value;
            if (!ss.fail()) {
                addToHeadL1(head, value);
                writeListToFile(head, "list1.txt");
            } else {
                cout << "> Неверный ввод. Необходимо ввести: ADDHEAD <значение>" << endl;
            }
        } 
        else if (action == "ADDTAIL") {
            ss >> value;
            if (!ss.fail()) {
                addToTailL1(head, value);
                writeListToFile(head, "list1.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: ADDTAIL <значение>" << endl;
            }
        } 
        else if (action == "REMOVEHEAD") {
            removeHeadL1(head);
            writeListToFile(head, "list1.txt");
        } 
        else if (action == "REMOVETAIL") {
            removeTailL1(head);
            writeListToFile(head, "list1.txt");
        } 
        else if (action == "REMOVEVALUE") {
            ss >> value;
            if (!ss.fail()) {
                removeByValueL1(head, value);
                writeListToFile(head, "list1.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: REMOVEVALUE <значение>" << endl;
            }
        } 
        else if (action == "SEARCH") {
            ss >> value;
            if (!ss.fail()) {
                cout << "Результат поиска для значения " << value << ": " 
                     << (searchL1(head, value) ? "Найдено" : "Не найдено") << endl;
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: SEARCH <значение>" << endl;
            }
        } 
        else if (action == "PRINT") {
            cout << "Содержимое списка: ";
            printList1(head);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, SEARCH, PRINT, EXIT." << endl;
        }
    }
}

void list2Cmds (DoubleList& list) {
    list.head = nullptr;
    list.tail = nullptr;

    string command;
    int value;

    cout << "Введите команду (ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, FIND, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "ADDHEAD") {
            ss >> value;
            if (!ss.fail()) {
                addToHeadL2(list, value);
                writeDoubleListToFile(list, "list2.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: ADDHEAD <значение>" << endl;
            }
        } 
        else if (action == "ADDTAIL") {
            ss >> value;
            if (!ss.fail()) {
                addToTailL2(list, value);
                writeDoubleListToFile(list, "list2.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: addtail <value>" << endl;
            }
        } 
        else if (action == "REMOVEHEAD") {
            removeFromHeadL2(list);
            writeDoubleListToFile(list, "list2.txt");
        } 
        else if (action == "REMOVETAIL") {
            removeFromTailL2(list);
            writeDoubleListToFile(list, "list2.txt");
        } 
        else if (action == "REMOVEVALUE") {
            ss >> value;
            if (!ss.fail()) {
                removeByValueL2(list, value);
                writeDoubleListToFile(list, "list2.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: REMOVEVALUE <значение>" << endl;
            }
        } 
        else if (action == "FIND") {
            ss >> value;
            if (!ss.fail()) {
                NodeL* result = findL2(list, value);
                cout << "Результат поиска для значения " << value << ": " 
                     << (result ? "Найдено" : "Не найдено") << endl;
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: FIND <значение>" << endl;
            }
        } 
        else if (action == "PRINT") {
            cout << "Содержимое списка: ";
            printList2(list);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, FIND, PRINT, EXIT." << endl;
        }
    }
}

void arrayCmds (Array& arr) {

    string command;
    int index, value;

    cout << "Введите команду (APPEND, INSERT, REMOVE, REPLACE, GET, DISPLAY, LENGTH, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "APPEND") {
            ss >> value;
            if (!ss.fail()) {
                appendArray(arr, value);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: APPEND <значение>" << endl;
            }
        } 
        else if (action == "INSERT") {
            ss >> index >> value;
            if (!ss.fail()) {
                insertArray(arr, index, value);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: insert <индекс> <значение>" << endl;
            }
        } 
        else if (action == "REMOVE") {
            ss >> index;
            if (!ss.fail()) {
                removeArray(arr, index);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: REMOVE <индекс>" << endl;
            }
        } 
        else if (action == "REPLACE") {
            ss >> index >> value;
            if (!ss.fail()) {
                replaceArray(arr, index, value);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: REPLACE <индекс> <значение>" << endl;
            }
        } 
        else if (action == "GET") {
            ss >> index;
            if (!ss.fail()) {
                int result = getArray(arr, index);
                if (result != -1) {
                    cout << "Элемент по индексу " << index << ": " << result << endl;
                }
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: GET <индекс>" << endl;
            }
        } 
        else if (action == "DISPLAY") {
            cout << "Содержимое массива: ";
            displayArray(arr);
        } 
        else if (action == "LENGTH") {
            cout << "Длина массива: " << lengthArray(arr) << endl;
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: APPEND, INSERT, REMOVE, REPLACE, GET, DISPLAY, LENGTH, EXIT." << endl;
        }
    }
}

void queueCmds (Queue& q) {
    q.head = q.tail = nullptr;

    string command;
    int value;

    cout << "Введите команду (ENQUEUE, DEQUEUE, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "ENQUEUE") {
            ss >> value;
            if (!ss.fail()) {
                enqueue(q, value);
                writeQueueToFile(q, "queue.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: ENQUEUE <значение>" << endl;
            }
        } 
        else if (action == "DEQUEUE") {
            int result = dequeue(q);
            writeQueueToFile(q, "queue.txt");
        } 
        else if (action == "PRINT") {
            printQueue(q);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: ENQUEUE, DEQUEUE, PRINT, EXIT." << endl;
        }
    }
}

void stackCmds (Stack& stack) {
    stack.top = nullptr;

    string command;
    int value;

    cout << "Введите команду (PUSH, POP, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "PUSH") {
            ss >> value;
            if (!ss.fail()) {
                pushStack(stack, value);
                writeStackToFile(stack, "stack.txt");
            } else {
                cout << "> Неверный ввод. Необходимо ввести: PUSH <значение>" << endl;
            }
        } 
        else if (action == "POP") {
            popStack(stack);
            writeStackToFile(stack, "stack.txt");
        } 
        else if (action == "PRINT") {
            printStack(stack);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Неизвестная команда. Допутимые команды: PUSH, POP, PRINT, EXIT." << endl;
        }
    }
}

void treeCmds (NodeT*& root) {
    string command;
    int value;

    cout << "Введите команду (INSERT, DELETE, SEARCH, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "INSERT") {
            ss >> value;
            if (!ss.fail()) {
                root = insertTree(root, value);
                writeAVLTreeToFile(root, "tree.txt");
            }
            else {
                cout << "> Неверный ввод. Необходимо ввести: INSERT <значение>" << endl;
            }
        } 
        else if (action == "DELETE") {
            ss >> value;
            if (!ss.fail()) {
                root = deleteNodeT(root, value);
                writeAVLTreeToFile(root, "tree.txt");
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: DELETE <значение>" << endl;
            }
        } 
        else if (action == "SEARCH") {
            if (ss >> value) {
                NodeT* result = searchTree(root, value);
                cout << "Результат поиска для значения " << value << ": " 
                     << (result ? "Найдено" : "Не найдено") << endl;
            } 
            else {
                cout << "> Неверный ввод. Необходимо ввести: SEARCH <значение>" << endl;
            }
        } 
        else if (action == "PRINT") {
            printTree(root);
            cout << endl;
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> neznay komandy. Допутимые команды: INSERT, DELETE, SEARCH, PRINT, EXIT." << endl;
        }
    }
}

int main() {
    system("chcp 65001");
    HashTable* hashTable[TABLE_SIZE] = {nullptr}; // Инициализация пустой хеш-таблицы
    ListOne* head = nullptr;
    DoubleList list;
    Array arr;
    initArray(arr, 2);
    Queue q;
    Stack stack;
    NodeT* root = nullptr;

    string command;

    cout << "> vybirite structuru dannyh (HASHTABLE, LIST1, LIST2, ARRAY, QUEUE, STACK, AVLTREE, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "HASHTABLE") {
            hashtableCmds(hashTable);
        } 
        else if (command == "LIST1") {
            list1Cmds(head);
        } 
        else if (command == "LIST2") {
            list2Cmds(list);
        } 
        else if (command == "ARRAY") {
            arrayCmds(arr);
        } 
        else if (command == "QUEUE") {
            queueCmds(q);
        } 
        else if (command == "STACK") {
            stackCmds(stack);
        } 
        else if (command == "AVLTREE") {
            treeCmds(root);
        } 
        else if (command == "EXIT") {
            break;
        } 
        else {
            cout << "> neznay komandu. dostup komandy: HASHTABLE, LIST1, LIST2, ARRAY, QUEUE, STACK, AVLTREE, EXIT." << endl;
        }
    }

    freeTable(hashTable);
    freeList1(head);
    freeList2(list);
    freeArray(arr);
    freeQueue(q);
    freeStack(stack);
    freeTree(root);

    return 0;
}
