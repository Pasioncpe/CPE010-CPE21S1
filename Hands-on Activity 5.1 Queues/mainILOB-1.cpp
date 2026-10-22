#include <iostream>
#include "queuell.h"

int main(){

    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue(&front, &back, 'T');
    enqueue(&front, &back, 'W');
    enqueue(&front, &back, 'A');
    enqueue(&front, &back, 'I');
    enqueue(&front, &back, 'N');
    display(&front, &back);
    dequeue(&front, &back);
    display(&front, &back);

    std::cout << Front(&front) << "\n";

    return 0;
}
