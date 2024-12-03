#include "tree.h"
#include <functional>

using namespace std;
// Конструктор класса корень дерева null
FullBinaryTree::FullBinaryTree() : root(nullptr) {}
// Деструктор Вызывает рекурсивную функцию для освобождения памяти, занимаемой деревом.
FullBinaryTree::~FullBinaryTree() {
    freeTree(root);
}
// Рекурсивная функция вставки узла 
NodeT* FullBinaryTree::insert(NodeT* root, int value) {
    if (!root) return new NodeT(value);
    if (value < root->value) root->left = insert(root->left, value); // Если значение меньше, рекурсивно вставляем в левое поддерево
    else root->right = insert(root->right, value);
    return root;
}

NodeT* FullBinaryTree::findMin(NodeT* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

NodeT* FullBinaryTree::remove(NodeT* root, int value) {//удаление узла
    if (!root) return nullptr;

    // Если знач меньше, рекурсивно удаляем из левого поддерева
    if (value < root->value) {
        root->left = remove(root->left, value);
    }
    // Если знач больше, рекурсивно удаляем из правого поддерева
    else if (value > root->value) {
        root->right = remove(root->right, value);
    }
    else {
       // Если нет лев и прав 
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
        else if (!root->right) {
            NodeT* temp = root->left;
            delete root;
            return temp;
        }
         // Если у узла есть два поддерева
        else {
            NodeT* temp = findMin(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
        }
    }
    return root;
}

NodeT* FullBinaryTree::search(NodeT* root, int value) const {
    if (!root || root->value == value) return root;
    if (value < root->value) return search(root->left, value);
    return search(root->right, value);
}

bool FullBinaryTree::isFull(NodeT* root) const {
    return isFullHelper(root);
}

bool FullBinaryTree::isFullHelper(NodeT* node) const {
    if (!node) return true;
    if ((node->left && !node->right) || (!node->left && node->right)) return false;
    return isFullHelper(node->left) && isFullHelper(node->right);
}

void FullBinaryTree::print(NodeT* root) const {
    printHelper(root, 0);
}

void FullBinaryTree::printHelper(NodeT* root, int level) const {
    if (!root) return;

    printHelper(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "    ";  
    }
    cout << root->value << endl;

    printHelper(root->left, level + 1);
}

void FullBinaryTree::writeToFile(NodeT* root, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return;

    ////лямбда-функци для обхода дерева в прямом порядке и записи в файл.
    function<void(NodeT*)> write = [&](NodeT* node) {
        if (!node) {
            file << "# ";
            return;
        }
        file << node->value << " ";
        write(node->left);
        write(node->right);
        };
    write(root);
    file.close();
}

NodeT* FullBinaryTree::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return nullptr;

    function<NodeT* ()> read = [&]() -> NodeT* {
        string val;
        file >> val;
        if (val == "#" || file.fail()) return nullptr;

        NodeT* node = new NodeT(stoi(val));
        node->left = read();
        node->right = read();
        return node;
        };
    root = read();
    file.close();
    return root;
}

void FullBinaryTree::freeTree(NodeT* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

