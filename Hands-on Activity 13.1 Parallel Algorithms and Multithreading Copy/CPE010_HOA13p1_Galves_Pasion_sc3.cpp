#include <iostream>
#include <thread>

int integer;

void addInteger(int i) {
    integer += i;
}

void display() {
    std::cout << "integer: " << integer << "\n";
}

int main() {
    std::thread T1(addInteger, 1);
    std::thread T2(addInteger, 2);
    std::thread T3(addInteger, 3);

    display();
    T1.join();

    display();
    T2.join();

    display();
    T3.join();

    return 0;
}
