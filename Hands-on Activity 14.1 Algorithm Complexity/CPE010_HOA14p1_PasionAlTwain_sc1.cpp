#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <chrono>
#include "sorting2.h"

void print(int arr[], int size) {
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    const int size = 20;
    int arr1[size];
    int arr2[size];

    const int seed = 67;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> give(1, 101);

    for (int i = 0; i < size; i++) {
        arr1[i] = give(gen);
    }

    std::copy(std::begin(arr1), std::end(arr1), arr2);

    std::cout << "\n---- UNSORTED ARRAYS (same seed generation) ----\n";
    print(arr1, size);
    print(arr2, size);

    std::cout << "\n---- QUICK SORT TIMING ----\n";
    auto t1 = std::chrono::high_resolution_clock::now();
    quickSort(arr1, 0, size-1);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    std::cout << "Time it took: " << duration << " nanoseconds\n";

    std::cout << "\n---- MERGE SORT TIMING ----\n";
    auto t3 = std::chrono::high_resolution_clock::now();
    mergeSort(arr2, 0, size-1);
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    std::cout << "Time it took: " << duration2 << " nanoseconds\n";

    std::cout << "\n---- SORTED ARRAY ----\n";
    print(arr1, size);

    int worst1[size];
    int worst2[size];

    for (int i = 0; i < size; i++) {
        worst1[i] = i;
        worst2[i] = i;
    }

    std::cout << "\n---- WORST CASE: ALREADY SORTED ARRAY (size " << size << ") ----\n";

    std::cout << "\n---- QUICK SORT TIMING (WORST CASE) ----\n";
    auto w1 = std::chrono::high_resolution_clock::now();
    quickSort(worst1, 0, size - 1);
    auto w2 = std::chrono::high_resolution_clock::now();

    auto worstDuration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( w2 - w1 ).count();
    std::cout << "Time it took: " << worstDuration1 << " nanoseconds\n";

    std::cout << "\n---- MERGE SORT TIMING (WORST CASE INPUT) ----\n";
    auto w3 = std::chrono::high_resolution_clock::now();
    mergeSort(worst2, 0, size - 1);
    auto w4 = std::chrono::high_resolution_clock::now();

    auto worstDuration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( w4 - w3 ).count();
    std::cout << "Time it took: " << worstDuration2 << " nanoseconds\n";
}
