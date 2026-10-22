#ifndef ILOC_H
#define ILOC_H

template<typename elmo>
class Node{
    public:
    elmo data;
    Node* next;
};

template<typename elmo>
Node<elmo>* head = nullptr;

template<typename elmo>
bool isEmpty(){
    return head<elmo> == nullptr;
}

template <typename elmo>
void push (elmo newData){
    if (newData != '(' && newData != '{' && newData != '['){
        return;
    }

    Node<elmo>* newNode = new Node<elmo>;
    newNode->data = newData;
    newNode->next = head<elmo>;
    head<elmo> = newNode;
}

template<typename elmo>
elmo pop(){
    if (isEmpty<elmo>()){
        std::cout << "stack undeflow\n";
        return elmo();
    }

    Node<elmo>* temp = head<elmo>;
    elmo temVAL = temp->data;
    
    head<elmo> = head<elmo>->next;
    delete temp;
    temp = nullptr;
    return temVAL;

}

template<typename elmo>
void Top(){
    if (isEmpty<elmo>()){
        std::cout << "stack undeflow\n";
        return;
    }
    std::cout << head<elmo>->data;
}

template<typename elmo>
void print(){
    
    if (head<elmo> == nullptr){
        std::cout << "stack underflow\n";
        return;
    }
    
    Node<elmo>* temp = head<elmo>;
    while (temp != nullptr) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << "\n";
    
}



#endif