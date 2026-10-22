#include <iostream>
#include <cstdlib>
#include <time.h>
#include "nodes.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main() {

    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }

    int toFind;
    std::cout << "\nValue to search: ";
    std::cin >> toFind;

    linearSearchArr(dataset, max_size, toFind);

    Node<char>* name1 = new_Node('T');
    Node<char>* name2 = new_Node('W');
    Node<char>* name3 = new_Node('A');
    Node<char>* name4 = new_Node('I');
    Node<char>* name5 = new_Node('N');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;

    std::cout << "Linear Search for LL result:\n";
    linearSearchLL(name1, 'I');

    std::cout << "Binary Search for LL result:\n";
    binarySearchLL(name1, 'N');

    std::cout << "Binary Search for Array result:\n";
    bubbleSortArr(dataset, max_size);
    binarySearchArr(dataset, max_size, toFind);

    name1->data = 'A';
    name2->data = 'B';
    name3->data = 'E';
    name4->data = 'H';
    name5->data = 'X';

    std::cout << "Binary Search for LL result:\n";
    binarySearchLL(name2, 'E');


    return 0;
}