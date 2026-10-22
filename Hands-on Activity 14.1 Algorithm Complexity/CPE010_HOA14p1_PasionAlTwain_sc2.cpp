#include <iostream>
#include <random>
#include <chrono>
#include "sorting2.h"
#include "searchingAlgo.h"

int main(){
    const int size1 = 1000;
    const int size2 = 10000;
    const int size3 = 100000;

    int arr1[size1];
    int arr2[size2];
    int arr3[size3];

    const int seed = 67;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> give(1, 1000000);

    for (int i = 0; i < size1; i++){
        arr1[i] = give(gen);
    }
    for (int i = 0; i < size2; i++){
        arr2[i] = give(gen);
    }
    for (int i = 0; i < size3; i++){
        arr3[i] = give(gen);
    }

    auto t1 = std::chrono::steady_clock::now();
    bool s1 = linearSearchArr(arr1, size1, -1);
    auto t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::nano> time1 = t2 - t1;

    if (s1) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Linear Searching for input size: " << size1 << std::endl;;

    quickSort(arr1, 0, size1-1);
    t1 = std::chrono::steady_clock::now();
    bool s2 = binarySearchArr(arr1, size1, -1);
    t2 = std::chrono::steady_clock::now();
    time1 = t2 - t1;

    if (s2) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Binary Searching for input size: " << size1 << std::endl;

    std::cout << std::endl;

    t1 = std::chrono::steady_clock::now();
    s1 = linearSearchArr(arr2, size2, -1);
    t2 = std::chrono::steady_clock::now();
    time1 = t2 - t1;

    if (s1) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Linear Searching for input size: " << size2 << std::endl;;

    quickSort(arr2, 0, size2-1);
    t1 = std::chrono::steady_clock::now();
    s2 = binarySearchArr(arr2, size2, -1);
    t2 = std::chrono::steady_clock::now();
    time1 = t2 - t1;

    if (s2) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Binary Searching for input size: " << size2 << std::endl;

    std::cout << std::endl;

    t1 = std::chrono::steady_clock::now();
    s1 = linearSearchArr(arr3, size3, -1);
    t2 = std::chrono::steady_clock::now();
    time1 = t2 - t1;

    if (s1) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Linear Searching for input size: " << size3 << std::endl;;

    quickSort(arr3, 0, size3-1);
    t1 = std::chrono::steady_clock::now();
    s2 = binarySearchArr(arr3, size3, -1);
    t2 = std::chrono::steady_clock::now();
    time1 = t2 - t1;

    if (s2) {
        std::cout << "Found!" << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    std::cout << time1.count() << " nanoseconds for Binary Searching for input size: " << size3 << std::endl;

}