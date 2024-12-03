#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "hashtable.h"
#include "List1.h"
#include "List2.h"
#include "arr.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

using namespace std;

void hashtableCmds(HashTable* hashTable[]) {
    string command;
    string key, value;

    cout << "Enter the command (INSERT, GET, REMOVE, PRINT, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action; // Извлекаем действие из команды

        if (action == "INSERT") {
            if (ss >> key >> value && !key.empty() && !value.empty()) {
                insertTable(hashTable, key, value);
                writeHashTableToFile(hashTable, "hashtable.txt");
            } 
            else {
                cout << "> Incorrect input. You must enter: INSERT <key> <value>" << endl;
            }
        } 
        else if (action == "GET") {
            if (ss >> key && !key.empty()) {
                cout << "Value: " << getValueTable(hashTable, key) << endl;
            } else {
                cout << "> Incorrect input. You must enter: GET <key>" << endl;
            }
        }
        else if (action == "REMOVE") {
            if (ss >> key && !key.empty()) {
                removeValueTable(hashTable, key);
                writeHashTableToFile(hashTable, "hashtable.txt");
            } 
            else {
                cout << "> Incorrect input. You must enter: REMOVE <key>" << endl;
            }
        } 
        else if (action == "PRINT") {
            printTable(hashTable);
        }
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Unknown command. Valid commands: INSERT, GET, REMOVE, PRINT, EXIT." << endl;
        }
    }
}

void list1Cmds (ListOne*& head) {
    string command;
    int value;

    cout << "Enter the command (ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, SEARCH, PRINT, EXIT):" << endl;

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
                cout << "> Incorrect input. You must enter: ADDHEAD <value>" << endl;
            }
        } 
        else if (action == "ADDTAIL") {
            ss >> value;
            if (!ss.fail()) {
                addToTailL1(head, value);
                writeListToFile(head, "list1.txt");
            } 
            else {
                cout << "> Incorrect input. You must enter: ADDTAIL <value>" << endl;
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
                cout << "> Incorrect input. You must enter: REMOVEVALUE <value>" << endl;
            }
        } 
        else if (action == "SEARCH") {
            ss >> value;
            if (!ss.fail()) {
                cout << "The search result for the value" << value << ": " 
                     << (searchL1(head, value) ? "Found" : "Not found") << endl;
            } 
            else {
                cout << "> Incorrect input. You must enter: SEARCH <value>" << endl;
            }
        } 
        else if (action == "PRINT") {
            cout << "Contents of the list: "; //Содержимое списка
            printList1(head);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Unknown command. Valid commands: ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, SEARCH, PRINT, EXIT." << endl;
        }
    }
}

void list2Cmds (DoubleList& list) {
    list.head = nullptr;
    list.tail = nullptr;

    string command;
    int value;

    cout << " Enter the command (ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, FIND, PRINT, EXIT):" << endl;

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
                cout << ">Incorrect input. It is necessary to enter: ADDHEAD <value>" << endl;
            }
        } 
        else if (action == "ADDTAIL") {
            ss >> value;
            if (!ss.fail()) {
                addToTailL2(list, value);
                writeDoubleListToFile(list, "list2.txt");
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: addtail <value>" << endl;
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
                cout << "> Incorrect input. It is necessary to enter: REMOVEVALUE <value>" << endl;
            }
        } 
        else if (action == "FIND") {
            ss >> value;
            if (!ss.fail()) {
                NodeL* result = findL2(list, value);
                cout << "The search result for the value " << value << ": " 
                     << (result ? "Found" : "Not found") << endl;
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: FIND <value>" << endl;
            }
        } 
        else if (action == "PRINT") {
            cout << "Contents of the list: ";
            printList2(list);
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Unknown command. Valid commands: ADDHEAD, ADDTAIL, REMOVEHEAD, REMOVETAIL, REMOVEVALUE, FIND, PRINT, EXIT." << endl;
        }
    }
}

void arrayCmds (Array& arr) {

    string command;
    int index, value;

    cout << "Enter the command (APPEND, INSERT, REMOVE, REPLACE, GET, DISPLAY, LENGTH, EXIT):" << endl;

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
                cout << "> Incorrect input. It is necessary to enter: APPEND <value>" << endl;
            }
        } 
        else if (action == "INSERT") {
            ss >> index >> value;
            if (!ss.fail()) {
                insertArray(arr, index, value);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: INSERT <index> <value>" << endl;
            }
        } 
        else if (action == "REMOVE") {
            ss >> index;
            if (!ss.fail()) {
                removeArray(arr, index);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: REMOVE <index>" << endl;
            }
        } 
        else if (action == "REPLACE") {
            ss >> index >> value;
            if (!ss.fail()) {
                replaceArray(arr, index, value);
                writeArrayToFile(arr, "array.txt");
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: REPLACE <index> <value>" << endl;
            }
        } 
        else if (action == "GET") {
            ss >> index;
            if (!ss.fail()) {
                int result = getArray(arr, index);
                if (result != -1) {
                    cout << "Element by index " << index << ": " << result << endl;
                }
            } 
            else {
                cout << "> Incorrect input. It is necessary to enter: GET <index>" << endl;
            }
        } 
        else if (action == "DISPLAY") {
            cout << "The contents of the array: ";
            displayArray(arr);
        } 
        else if (action == "LENGTH") {
            cout << "Array length: " << lengthArray(arr) << endl;
        } 
        else if (action == "EXIT") {
            break;
        } 
        else {
            cout << "> Unknown command. Valid commands: APPEND, INSERT, REMOVE, REPLACE, GET, DISPLAY, LENGTH, EXIT." << endl;
        }
    }
}

void queueCmds (Queue& q) {
    q.head = q.tail = nullptr;

    string command;
    int value;

    cout << "Print commands (ENQUEUE, DEQUEUE, PRINT, EXIT):" << endl;

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
                cout << "> Incorrect input. It is necessary to enter: ENQUEUE <value>" << endl;
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
            cout << "> Unknown command. Valid commands: ENQUEUE, DEQUEUE, PRINT, EXIT." << endl;
        }
    }
}

void stackCmds (Stack& stack) {
    stack.top = nullptr;

    string command;
    int value;

    cout << "Enter the command (PUSH, POP, PRINT, EXIT):" << endl;

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
                cout << "> Incorrect input. You must enter: PUSH <value>" << endl;
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
            cout << "> Unknown command. Valid commands: PUSH, POP, PRINT, EXIT." << endl;
        }
    }
}

void treeCmds(NodeT*& root, FullBinaryTree& tree) {
    string command;
    int value;

    // загрузка из файла
    root = tree.readFromFile("tree.txt");
    if (root) {
        cout << "> Tree loaded from file." << endl;
    }
    else {
        cout << "> No tree found in file, starting with an empty tree." << endl;
    }

    cout << "Enter the command (INSERT, DELETE, SEARCH, PRINT, CHECK_FULL, EXIT):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "INSERT") {
            ss >> value;
            if (!ss.fail()) {
                root = tree.insert(root, value);
                tree.writeToFile(root, "tree.txt");  
                cout << "> Value " << value << " inserted." << endl;
            }
            else {
                cout << "> Incorrect input. You must enter: INSERT <value>" << endl;
            }
        }
        else if (action == "DELETE") {
            ss >> value;
            if (!ss.fail()) {
                root = tree.remove(root, value);
                tree.writeToFile(root, "tree.txt");  
                cout << "> Value " << value << " deleted." << endl;
            }
            else {
                cout << "> Incorrect input. You must enter: DELETE <value>" << endl;
            }
        }
        else if (action == "SEARCH") {
            if (ss >> value) {
                NodeT* result = tree.search(root, value);
                cout << "The search result for the value " << value << ": "
                    << (result ? "Found" : "Not found") << endl;
            }
            else {
                cout << "> Incorrect input. You must enter: SEARCH <value>" << endl;
            }
        }
        else if (action == "PRINT") {
            tree.print(root);
            cout << endl;
        }
        else if (action == "CHECK_FULL") {
            if (tree.isFull(root)) {
                cout << "> The tree is full." << endl;
            }
            else {
                cout << "> The tree is not full." << endl;
            }
        }
        else if (action == "EXIT") {
            tree.writeToFile(root, "tree.txt");  
            cout << "> Tree saved to file." << endl;
            break;
        }
        else {
            cout << "> Unknown command. Valid commands: INSERT, DELETE, SEARCH, PRINT, CHECK_FULL, EXIT." << endl;
        }
    }
}

int main() {
    HashTable* hashTable[TABLE_SIZE] = {nullptr}; 
    ListOne* head = nullptr;
    DoubleList list;
    Array arr;
    initArray(arr, 2);
    Queue q;
    Stack stack;
    FullBinaryTree tree;
    NodeT* root = nullptr;

    string command;

    cout << "> Select the data structure (HASHTABLE, LIST1, LIST2, ARRAY, QUEUE, STACK, FULLBINTREE, EXIT):" << endl; //Выберите структуру данных 

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
       else if (command == "FULLBINTREE") {
            treeCmds(root, tree);
        } 
        else if (command == "EXIT") {
            break;
        } 
        else {
            cout << "> Unknown command. Available commands: HASHTABLE, LIST1, LIST2, ARRAY, QUEUE, STACK, FULLBINTREE, EXIT." << endl;
        }
    }

    freeTable(hashTable);
    freeList1(head);
    freeList2(list);
    freeArray(arr);
    freeQueue(q);
    freeStack(stack);
    tree.freeTree(root);

    return 0;
}
