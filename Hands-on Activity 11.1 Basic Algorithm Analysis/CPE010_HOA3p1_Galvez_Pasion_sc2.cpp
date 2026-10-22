#include <iostream>
#include <random>
#include <chrono>
bool unique(int arr[], size_t n);

int main() {
    const size_t n = 10;
    int arr[n];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    std::cout << "Generetated Array: [ ";
    for (size_t i = 0; i < n; ++i) {
        arr[i] = dist(gen);
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool result = unique(arr, n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;

    if (result) {
        std::cout << "Result: it's unique\n";
    } else {
        std::cout << "Result: it's not unique\n";
    }
    return 0;
}
bool unique(int arr[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true; 
}