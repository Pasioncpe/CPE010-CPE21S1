#include <iostream>
#include <queue>

void display(std::queue<char> r);
void empty(std::queue<char> o);
void size (std::queue<char> b);
void front(std::queue<char> l);
void back(std::queue<char> o);

int main(){

    std::queue<char> q; 

    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //display
    display(q);
    //empty
    empty(q);
    //size
    size(q);
    //front
    front(q);
    //back
    back(q);
    //pop
    q.pop();
    display(q);
    //push another elemet
    q.push('e');
    display(q);

    //delete all
    while (!q.empty()){
        q.pop();
    }
    display(q);


    return 0;
}

void display(std::queue<char> r){
    
    std::queue<char> c = r;

    if (c.empty()){
        std::cout << "The queue is empty\n";
        return;
    }

    while(!c.empty()){
        std::cout << c.front() << " ";
        c.pop();
    }
    std::cout << "\n";
}

void empty(std::queue<char> r){
    if (r.empty()){
        std::cout << "The queue is empty\n";
    }
    else {
        std::cout << "The queue is not empty\n";
    }
}

void size(std::queue<char> b){
    std::cout << "There are " << b.size() << " things in line\n";
}

void front(std::queue<char> l){
    std::cout << l.front() << " is at the front\n";
}

void back(std::queue<char> o){
    std::cout << o.back() << " is at the back\n";
}



