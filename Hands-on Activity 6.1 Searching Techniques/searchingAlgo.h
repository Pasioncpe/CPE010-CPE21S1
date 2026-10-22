#include <algorithm>

#include "nodes.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(T data[], int arrSize, T datafind) {
    int i = 0;
    while (i < arrSize) {
        if (data[i] == datafind) {
            std::cout << "Search Success\n";
            std::cout << "Comparison Count: " << i+1 << "\n";
            return;
        }
        i++;
    }
    std::cout << "Element not found\n";
    std::cout << "Comparison Count: " << i << "\n";
}

template <typename T>
void linearSearchArrMOD(T data[], int arrSize, T datafind) {
    int i = 0;
    int counter = 0;
    while (i < arrSize) {
        if (data[i] == datafind) {
            counter++;
        }
        i++;
    }
    std::cout << "Count: " << counter << "\n";
}

template <typename T>
void linearSearchLL(Node<T>* node, T datafind) {
    int counter = 1;
    while (node != nullptr) {
        if (node->data == datafind) {
            std::cout << "Search Success\n";
            std::cout << "Comparison Count: " << counter << "\n";
            return;
        }
        node = node->next;
        counter++;
    }
    std::cout << "Element not found\n";
    std::cout << "Comparison Count: " << counter-1 << "\n";
}

template <typename T>
void linearSearchLLMOD(Node<T>* node, T datafind) {
    int counter = 0;
    while (node != nullptr) {
        if (node->data == datafind) {
            counter++;
        }
        node = node->next;
    }
    std::cout << "Count: " << counter << "\n";
}

template <typename T>
Node<T>* getMiddleLL (Node<T>* start, Node<T>* last) {
    Node<T>* slow = start;
    Node<T>* fast = start;
    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int getMiddleArr(int low, int high) {
    return low + (high - low) / 2;
}

template <typename T>
void binarySearchLL(Node<T>* head, T dataFind) {
    Node<T>* start = head;
    Node<T>* last = nullptr;

    while (start != last) { //if start == last, it means that they did not find the data
        Node<T>* middle = getMiddleLL(start, last);
        if (middle->data == dataFind) {
            std::cout << "Search Success\n";
            return;
        }
        else if (middle->data > dataFind) {
            last = middle;
        }
        else { //middle->data < dataFind
            start = middle->next;
        }
    }
    std::cout << "Search Failed\n";
}

template <typename T>
void binarySearchArr(T data[], int arrSize,T dataFind) {
    int low = 0;
    int high = arrSize - 1;

    while (low <= high) {
        int middle = getMiddleArr(low, high);

        if (data[middle] == dataFind) {
            std::cout << "Search Success\n";
            return;
        }
        else if (data[middle] > dataFind) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    std::cout << "Search Failed\n";
}

template <typename T>
void binarySearchArrMOD(T data[], int arrSize,T dataFind, int low, int high) {
    if (low <= high) {
        int middle = getMiddleArr(low, high);
        if (data[middle] == dataFind) {
            std::cout << "Search Success\n";
            return;
        }
        else if (data[middle] > dataFind) {
            high = middle - 1;
            binarySearchArrMOD(data, arrSize, dataFind, low, high);
            return;
        }
        else {
            low = middle + 1;
            binarySearchArrMOD(data, arrSize, dataFind, low, high);
            return;
        }
    }
    std::cout << "Search Failed\n";
}

template <typename T>
void bubbleSortArr(T data[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

#endif
