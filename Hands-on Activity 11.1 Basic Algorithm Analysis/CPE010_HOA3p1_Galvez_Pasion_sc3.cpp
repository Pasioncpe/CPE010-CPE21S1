#include <iostream>
#include <chrono>

int rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

int brpower(int x, int n) {
    if (n == 0) return 1;

    if (n % 2 == 1) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    else {
        int y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x, n;

    std::cout << "Enter base x: ";
    std::cin >> x;
    std::cout << "Enter nonnegative exponent n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "n must be nonnegative." << std::endl;
        return 1;
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::cout << "rpower("  << x << ", " << n << ") = " << rpower(x, n)  << std::endl;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time taken to compute = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    std::cout << "brpower(" << x << ", " << n << ") = " << brpower(x, n) << std::endl;
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

    std::cout << "Time taken to compute = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count()
              << " microseconds" << std::endl;
    return 0;
}