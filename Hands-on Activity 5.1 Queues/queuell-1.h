#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode{
    public:
    T data;
    qNode* next;
};


//create new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}


template <typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){
    qNode<T>* newNode = new_node(newData);

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);

    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
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
void display(qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* temp = (*frontPtr);

    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        std::cout << "Queue is empty\n";
        return;
    } 

    do {
        std::cout << temp->data << " ";
        temp = temp->next;

    } while(temp != nullptr);
    std::cout << "\n";
}

template <typename T>
T Front(qNode<T>** frontPtr){
    return (*frontPtr)->data;
}

#endif