#include <iostream>

int DIST(int first, int end);

int main() {
    std::cout << DIST(23,98);
}

int DIST(int first, int end) {
    return end - first;
}