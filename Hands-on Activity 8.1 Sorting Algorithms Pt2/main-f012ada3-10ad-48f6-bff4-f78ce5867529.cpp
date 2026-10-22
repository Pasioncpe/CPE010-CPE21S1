#include <iostream>
#include <random>
#include "sorting2.h"
void displayArray(int arr[], int size);
const int size = 100;

int main() {
    int dataset[size];
    int dataset2[size];
    int dataset3[size];

    std::random_device rd;
    std::mt19937 number(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < size; i++) {
        dataset[i] = dist(number);
    }
    for (int i = 0; i < size; i++) {
        dataset2[i] = dist(number);
    }
    for (int i = 0; i < size; i++) {
        dataset3[i] = dist(number);
    }

    std::cout << "\n\nShell Sorted Array\n";
    shellSort(dataset, size);
    displayArray(dataset, size);

    std::cout << "\n\nMerge Sorted Array\n";
    mergeSort(dataset2, 0, size - 1);
    displayArray(dataset2, size);

    std::cout << "\n\nQuick Sorted Array\n";
    quickSort(dataset3, 0, size);
    displayArray(dataset3, size);

    return 0;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}