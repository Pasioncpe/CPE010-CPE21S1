#include <iostream>

double KtoF(double k);

int main(){
    std::cout << KtoF(300);
}

double KtoF(double k) {
    return (((k - 273.15)*(1.8))+ 32);
}