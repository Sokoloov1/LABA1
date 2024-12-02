#ifndef FULLBINARYTREE_H
#define FULLBINARYTREE_H

#include <iostream>
#include <fstream>
#include <string>

struct NodeT {
    int value;
    NodeT* left;
    NodeT* right;

    NodeT(int val) : value(val), left(nullptr), right(nullptr) {}
};

class FullBinaryTree {
public:
    FullBinaryTree();
    ~FullBinaryTree();

    NodeT* insert(NodeT* root, int value);
    NodeT* findMin(NodeT* root);
    NodeT* remove(NodeT* root, int value);
    NodeT* search(NodeT* root, int value) const;
    bool isFull(NodeT* root) const;
    void print(NodeT* root) const;

    void printHelper(NodeT* root, int level) const;

    void writeToFile(NodeT* root, const std::string& filename);
    NodeT* readFromFile(const std::string& filename);

    void freeTree(NodeT* root);

private:
    NodeT* root;
    bool isFullHelper(NodeT* node) const;
};

#endif
