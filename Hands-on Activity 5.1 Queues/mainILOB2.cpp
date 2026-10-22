#include <iostream>
#include "queuearray.h"

int main() {

    qarray<int> q(5);
    std::cout << "q_empty: " << q.Empty() << " q_full: " << q.Full() << " q_size: " << q.Size() << std::endl;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    std::cout << "New Elements -> q_front: " << q.Front() << " q_back: " << q.Back() << " q_empty: " << q.Empty() << " q_full: " << q.Full() << " q_size: " << q.Size() << std::endl;

    q.Enqueue(6);

    q.Dequeue();
    q.Dequeue();
    std::cout << "After 2 dequeues -> q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;

    q.Enqueue(6);
    q.Enqueue(7); // wraps around to the start of the array
    std::cout << "After wraparound -> q_front: " << q.Front() << " q_back: " << q.Back() << " q_size: " << q.Size() << std::endl;

    qarray<int> Copy(q);
    Copy.Dequeue();
    Copy.Enqueue(99);
    std::cout << "q_back: " << q.Back() << " Copy_back: " << Copy.Back() << std::endl;

    qarray<int> Assign(3);
    Assign = q;
    std::cout << "Assign_front: " << Assign.Front() << " Assign_back: " << Assign.Back() << " qAssign_size: " << Assign.Size() << std::endl;

    q.Clear();
    std::cout << "After Clear -> q_empty: " << q.Empty() << " q_size: " << q.Size() << std::endl;

    q.Dequeue();
    return 0;
}