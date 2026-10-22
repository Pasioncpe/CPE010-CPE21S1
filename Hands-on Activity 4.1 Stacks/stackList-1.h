#ifndef STACK_LIST_H
#define STACK_LIST_H


template<typename T>
class Node{
    public:
    T data;
    Node* next;
};

template<typename T>
Node<T>* head = nullptr;


template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
void push (T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

template<typename T>
T pop (){
    if (head<T> == nullptr){
        std::cout << "stack undeflow\n";
        return T();
    }

    Node<T>* temp = head<T>;
    T temVAL = temp->data;
    
    head<T> = head<T>->next;
    delete temp;
    temp = nullptr;
    return temVAL;

};

template<typename T>
void Top(){
    if (head<T> == nullptr){
        std::cout << "stack underflow\n";
        return;
    }
    std::cout << "The top is: " << head<T>->data << "\n";
};



template<typename T>
void print(){
    
    if (head<T> == nullptr){
        std::cout << "stack underflow\n";
        return;
    }
    
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << "\n";
    
}

#endif