#include <iostream>
#include <stack>
// commands (so far)
/*
    .empty
    .push
    .pop
    .swap
    .top
    .size
*/

int main(){

    std::stack<int> newStack;

    std::cout << "Stack Empty? " << newStack.empty() << "\n";

    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    std::cout << "Stack Empty? " << newStack.empty() << "\n";
    std::cout << "The size of the stack: " << newStack.size() << "\n";
    std::cout << "The top of the stack: " << newStack.top() << "\n";

    std::cout << "Removing elements from stack: \n";
    newStack.pop();
    std::cout << "The top of the stack: " << newStack.top() << "\n";
    newStack.pop();
    std::cout << "The top of the stack: " << newStack.top() << "\n";
    newStack.pop();
    std::cout << "Stack Empty? " << newStack.empty() << "\n";

    return 0;
}
