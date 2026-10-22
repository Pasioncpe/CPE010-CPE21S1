#include <iostream>
#include <random>
#include "sortingSUPP.h"
void displayArray(int arr[], int size);
const int size = 100;

int main() {
    int dataset[size];

    std::random_device rd;
    std::mt19937 number(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < size; i++) {
        dataset[i] = dist(number);
    }

    std::cout << "\n\nQuick Sorted Array\n";
    quickSort(dataset, 0, size);
    displayArray(dataset, size);

    return 0;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}