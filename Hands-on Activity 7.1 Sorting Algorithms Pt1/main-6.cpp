#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int size = 100;
void displayArray(int arr[], int size);
void randomArray(int arr[], int size);

int main() {
    srand(time(0));

    int dataset[size];
    int dataset2[size];
    int dataset3[size];

    randomArray(dataset, size);
    randomArray(dataset2, size);
    randomArray(dataset3, size);

    std::cout << "\nUnsorted Dataset1: \n";
    displayArray(dataset, size);

    std::cout << "\nBubblesort: \n";
    bubbleSort(dataset, size);
    displayArray(dataset, size);

    std::cout << "\nUnsorted Dataset2: \n";
    displayArray(dataset2, size);

    std::cout << "\nInsertionsort: \n";
    insertionSort(dataset2, size);
    displayArray(dataset2, size);

    std::cout << "\nUnsorted Dataset3: \n";
    displayArray(dataset3, size);

    std::cout << "\nSelectionsort: \n";
    selectionSort(dataset3, size);
    displayArray(dataset3, size);

    return 0;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void randomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}