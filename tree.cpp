#include "tree.h"
#include <functional>

using namespace std;

// Конструктор класса: инициализирует корень дерева как nullptr
FullBinaryTree::FullBinaryTree() : root(nullptr) {}

// Деструктор: вызывает рекурсивную функцию для освобождения памяти, занимаемой деревом
FullBinaryTree::~FullBinaryTree() {
    freeTree(root);
}

// Рекурсивная функция вставки узла
NodeT* FullBinaryTree::insert(NodeT* root, int value) {
    if (!root) return new NodeT(value); // Если узел пустой, создаем новый узел
    if (value < root->value) root->left = insert(root->left, value); // Если значение меньше, рекурсивно вставляем в левое поддерево
    else root->right = insert(root->right, value); // Иначе, рекурсивно вставляем в правое поддерево
    return root;
}

// Функция поиска минимального элемента в дереве
NodeT* FullBinaryTree::findMin(NodeT* root) {
    while (root && root->left) {
        root = root->left; // Переходим к самому левому узлу
    }
    return root;
}

// Рекурсивная функция удаления узла
NodeT* FullBinaryTree::remove(NodeT* root, int value) {
    if (!root) return nullptr; // Если узел пустой, возвращаем nullptr

    // Если значение меньше, рекурсивно удаляем из левого поддерева
    if (value < root->value) {
        root->left = remove(root->left, value);
    }
    // Если значение больше, рекурсивно удаляем из правого поддерева
    else if (value > root->value) {
        root->right = remove(root->right, value);
    }
    else {
        // Если у узла нет левого и правого поддерева
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Если у узла есть только правое поддерево
        else if (!root->left) {
            NodeT* temp = root->right;
            delete root;
            return temp;
        }
        // Если у узла есть только левое поддерево
        else if (!root->right) {
            NodeT* temp = root->left;
            delete root;
            return temp;
        }
        // Если у узла есть два поддерева
        else {
            NodeT* temp = findMin(root->right); // Находим минимальный элемент в правом поддереве
            root->value = temp->value; // Копируем значение минимального элемента в текущий узел
            root->right = remove(root->right, temp->value); // Удаляем минимальный элемент из правого поддерева
        }
    }
    return root;
}

// Рекурсивная функция поиска узла
NodeT* FullBinaryTree::search(NodeT* root, int value) const {
    if (!root || root->value == value) return root; // Если узел пустой или найден, возвращаем узел
    if (value < root->value) return search(root->left, value); // Если значение меньше, ищем в левом поддереве
    return search(root->right, value); // Иначе, ищем в правом поддереве
}

// Функция проверки, является ли дерево полным
bool FullBinaryTree::isFull(NodeT* root) const {
    return isFullHelper(root);
}

// Рекурсивная функция проверки, является ли дерево полным
bool FullBinaryTree::isFullHelper(NodeT* node) const {
    if (!node) return true; // Если узел пустой, дерево полное
    if ((node->left && !node->right) || (!node->left && node->right)) return false; // Если у узла есть только одно поддерево, дерево не полное
    return isFullHelper(node->left) && isFullHelper(node->right); // Рекурсивно проверяем левое и правое поддерево
}

// Функция вывода дерева на экран
void FullBinaryTree::print(NodeT* root) const {
    printHelper(root, 0);
}

// Рекурсивная функция вывода дерева на экран
void FullBinaryTree::printHelper(NodeT* root, int level) const {
    if (!root) return; // Если узел пустой, выходим

    printHelper(root->right, level + 1); // Рекурсивно выводим правое поддерево

    for (int i = 0; i < level; i++) {
        cout << "    ";  // Выводим отступы в зависимости от уровня
    }
    cout << root->value << endl; // Выводим значение узла

    printHelper(root->left, level + 1); // Рекурсивно выводим левое поддерево
}

// Функция записи дерева в файл
void FullBinaryTree::writeToFile(NodeT* root, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return; // Если файл не открыт, выходим

    // Лямбда-функция для обхода дерева в прямом порядке и записи в файл
    function<void(NodeT*)> write = [&](NodeT* node) {
        if (!node) {
            file << "# "; // Если узел пустой, записываем "#"
            return;
        }
        file << node->value << " "; // Записываем значение узла
        write(node->left); // Рекурсивно записываем левое поддерево
        write(node->right); // Рекурсивно записываем правое поддерево
    };
    write(root);
    file.close();
}

// Функция чтения дерева из файла
NodeT* FullBinaryTree::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return nullptr; // Если файл не открыт, возвращаем nullptr

    // Лямбда-функция для чтения дерева из файла
    function<NodeT* ()> read = [&]() -> NodeT* {
        string val;
        file >> val;
        if (val == "#" || file.fail()) return nullptr; // Если встретили "#" или ошибка чтения, возвращаем nullptr

        NodeT* node = new NodeT(stoi(val)); // Создаем новый узел с прочитанным значением
        node->left = read(); // Рекурсивно читаем левое поддерево
        node->right = read(); // Рекурсивно читаем правое поддерево
        return node;
    };
    root = read();
    file.close();
    return root;
}

// Рекурсивная функция освобождения памяти, занимаемой деревом
void FullBinaryTree::freeTree(NodeT* root) {
    if (!root) return; // Если узел пустой, выходим
    freeTree(root->left); // Рекурсивно освобождаем левое поддерево
    freeTree(root->right); // Рекурсивно освобождаем правое поддерево
    delete root; // Удаляем текущий узел
}
