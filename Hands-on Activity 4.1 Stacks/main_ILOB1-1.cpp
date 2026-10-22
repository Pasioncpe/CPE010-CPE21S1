#include <iostream>

void push();
void pop();
void top();
bool empty();
bool full();
void print();

const size_t maxCap = 100;

int stack[maxCap];
int Top = -1;
int i, newData = 0;

int main(){
    
    int choice;

    std::cout << "Enter the number of max element for stack: ";
    std::cin >> i;
    
    while(true){
        std::cout << "Stack operations\n";
        std::cout << "1. PUSH\n2. POP\n3. TOP\n4. EMPTY\n5. END PROGRAM\n6. PRINT\n";
        std::cin >> choice;

        switch(choice){
            case 1: 
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            top();
            break;

            case 4:
            empty();
            break; 

            case 5:
            return 0;

            case 6:
            print();
            break;

            default:
            std::cout << "Invalid Choice\n";
        }
    }

    return 0;
}

bool empty(){
    if (Top == -1){
        return true;
    }
    else {
        return false; 
    }
}

bool full(){
    if ( Top >= i-1){
        return true;
    }
    else {
        return false;
    }
}

void push(){
    if (full()) {
        std::cout << "stack overflow";
        return;
    }
    std::cout << "New value to add into stack: ";
    std::cin >> newData;
    stack[++Top] = newData;
}

void top(){
    if(empty()){
        std::cout << "Stack underflow\n";
        return;
    }

    std::cout << "The element on the top of stack is: " <<stack[Top] << std::endl;

}

void pop(){
    if(empty()){
        std::cout << "Stack underflow\n";
        return;
    }

    std::cout << "Popping: " << stack[Top] << std::endl;
    Top--;
}

void print(){

    if(empty()){
        std::cout << "No stack to print\n";
        return;
    }

    else{
        
        for (int j = Top; j != -1; j--){
        std::cout << stack[j] << ", ";
    }
    std::cout << std::endl;
    }
    
}
