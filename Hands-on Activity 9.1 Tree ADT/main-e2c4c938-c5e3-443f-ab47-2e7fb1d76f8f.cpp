#include <iostream>
#include "GeneralTree.h"

int main() {
    TreeNode<char> A('A');

    // Children of A
    A.addChild('B');
    A.addChild('C');
    TreeNode<char>* D = A.addChild('D');
    TreeNode<char>* E = A.addChild('E');
    TreeNode<char>* F = A.addChild('F');
    TreeNode<char>* G = A.addChild('G');

    // D -> H
    D->addChild('H');

    // E -> I, J
    E->addChild('I');
    TreeNode<char>* J = E->addChild('J');

    // J -> P, Q
    J->addChild('P');
    J->addChild('Q');

    // F -> K, L, M
    F->addChild('K');
    F->addChild('L');
    F->addChild('M');

    // G -> N
    G->addChild('N');

    std::cout << "Pre-order:  ";
    A.preOrder();
    std::cout << "\nIn-order:   ";
    A.inOrder();
    std::cout << "\nPost-order: ";
    A.postOrder();
    std::cout << std::endl;

    return 0;
}