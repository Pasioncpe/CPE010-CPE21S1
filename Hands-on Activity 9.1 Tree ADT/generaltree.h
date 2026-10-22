#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <iostream>

const int MAX_CHILDREN = 10;   // max number of children per node

template <typename T>
class TreeNode {
private:
    T key;
    TreeNode<T>* children[MAX_CHILDREN];   // array of child pointers
    int childCount;                        // how many children are used

public:
    // Constructor
    TreeNode(T value);

    // Destructor
    ~TreeNode();

    // Tree building / checking
    TreeNode<T>* addChild(T value);
    bool isLeaf();

    // Traversing algorithms
    void preOrder();
    void inOrder();
    void postOrder();
};

template <typename T>
TreeNode<T>::TreeNode(T value) {
    key = value;
    childCount = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        children[i] = nullptr;
    }
}

template <typename T>
TreeNode<T>::~TreeNode() {
    for (int i = 0; i < childCount; i++) {
        delete children[i];
    }
}

// Adds a child (after the existing children) and returns it
template <typename T>
TreeNode<T>* TreeNode<T>::addChild(T value) {
    if (childCount >= MAX_CHILDREN) {
        std::cout << "Cannot add more children to " << key << std::endl;
        return nullptr;
    }
    children[childCount] = new TreeNode<T>(value);
    childCount++;
    return children[childCount - 1];
}

// Returns true if the node has no children
template <typename T>
bool TreeNode<T>::isLeaf() {
    return childCount == 0;
}

// Pre-order: Root -> Left -> Right
// first child is Left, the remaining children are Right
template <typename T>
void TreeNode<T>::preOrder() {
    std::cout << key << " ";
    for (int i = 0; i < childCount; i++) {
        children[i]->preOrder();
    }
}

// In-order: Left -> Root -> Right
template <typename T>
void TreeNode<T>::inOrder() {
    if (isLeaf()) {
        std::cout << key << " ";
        return;
    }
    children[0]->inOrder();
    std::cout << key << " ";
    for (int i = 1; i < childCount; i++) {
        children[i]->inOrder();
    }
}

// Post-order: Left -> Right -> Root
template <typename T>
void TreeNode<T>::postOrder() {
    for (int i = 0; i < childCount; i++) {
        children[i]->postOrder();
    }
    std::cout << key << " ";
}

#endif