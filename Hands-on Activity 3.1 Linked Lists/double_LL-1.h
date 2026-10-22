#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template<typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

template<typename T>
doubleList<T>* new_Node (T newData) {

    doubleList<T>* newNode = new doubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

template<typename T>
void dllTraverse(doubleList<T>* currentNode) {
    doubleList<T>* tail;

    std::cout << "Forward \n";
    //start to end
    while (currentNode != nullptr) {
        std::cout << currentNode->data << "->";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout<<std::endl;
    std::cout << "Reverse \n";
    //end to start
    while (tail != nullptr) {
        std::cout << tail->data << "->";
        tail = tail->prev;
    }
}

template<typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {
    doubleList<T>* newNode = new_Node(newData);
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;
    *currentHead = newNode;
}

template<typename T>
void dllInsertTail(T newData, doubleList<T>* currentHead) {
    doubleList<T>* newNode = new_Node(newData);

    while (currentHead->next != nullptr) {
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template<typename T>
void dllGeneralinsertion(T newData, doubleList<T>* prevNode) {
    if (prevNode == nullptr){
        std::cout << "Previous node cannot be null.\n";
        return;
    }
    doubleList<T>* newNode = new_Node(newData);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}


template<typename T>
void dllDelete(T findData, doubleList<T>** head) {
    if (*head == nullptr) {
        return;
    }
    doubleList<T>* currentNode = *head;
    doubleList<T>* prevNode = nullptr;

    while(currentNode != nullptr && currentNode->data != findData){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == nullptr){
        return;
    }
    if (prevNode == nullptr){
        *head = currentNode->next;
        if (*head != nullptr) {
            (*head)->prev = nullptr;
        }
    }
    else{
        prevNode->next = currentNode->next;
        if (currentNode->next != nullptr){
            currentNode->next->prev = prevNode;
        }
        delete currentNode;
    }
}

#endif