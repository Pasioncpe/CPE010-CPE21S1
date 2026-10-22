#include <iostream>

int main() {
    int a = 2;
    int b = 3;
    int c;
    std::cout << a << " " << b << std::endl;
    c = a; a = b; b = c;
    std::cout << a << " " << b << std::endl;
}