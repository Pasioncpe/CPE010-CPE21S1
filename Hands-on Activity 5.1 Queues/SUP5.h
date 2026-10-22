#ifndef HOA_5_SUP5_H
#define HOA_5_SUP5_H

template <typename T>
class Printer {
public:
    T data;
    Printer* next;
};

// create new node
template <typename T>
Printer<T>* new_node(T newData) {
    Printer<T>* newNode = new Printer<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void enqueue(Printer<T>** frontPtr, Printer<T>** backPtr, T newData) {
    Printer<T>* newNode = new_node(newData);

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(Printer<T>** frontPtr, Printer<T>** backPtr) {
    if ((*frontPtr) == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }

    Printer<T>* deleteNode = (*frontPtr);

    if ((*frontPtr) == (*backPtr)) {

        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

template <typename T>
T Front(Printer<T>** frontPtr) {
    return (*frontPtr)->data;
}

#endif //HOA_5_SUP5_H
