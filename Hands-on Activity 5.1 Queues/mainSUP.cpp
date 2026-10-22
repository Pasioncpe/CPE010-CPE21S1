#include <iostream>
#include <string>
#include "SUP5.h"

class Job {
public:
    int id;
    std::string name;
    int pages;
};

void printJob(const Job& j);

Printer<Job>* front = nullptr;
Printer<Job>* back = nullptr;

void displayall();
void frontdisplay();

int main() {

    std::cout << "=== People sending jobs to the printer ===\n";

    Job p1{1, "Jason", 3};
    Job p2{2, "Maria", 23};
    Job p3{3, "Ken", 7};
    Job p4{4, "Liam", 12};

    enqueue(&front, &back, p1);
    std::cout << "Jason added a job.\n";

    enqueue(&front, &back, p2);
    std::cout << "Maria added a job.\n";

    enqueue(&front, &back, p3);
    std::cout << "Ken added a job.\n";

    enqueue(&front, &back, p4);
    std::cout << "Liam added a job.\n";

    std::cout << "\n=== Current print queue ===\n";
    displayall();

    std::cout << "\n=== Printer processing jobs one by one ===\n";
    while (front != nullptr) {
        std::cout << "Now printing: ";
        printJob(Front(&front));
        dequeue(&front, &back);
    }
    std::cout << "\nAll jobs have been printed.\n";
    dequeue(&front, &back);

    return 0;
}

void printJob(const Job& j) {
    std::cout << "ID: " << j.id << " Name: " << j.name << " Pages: " << j.pages << "\n";
}

void displayall() {
    Printer<Job>* temp = front;
    while (temp != nullptr) {
        printJob(temp->data);
        temp = temp->next;
    }
}

void frontdisplay() {
    printJob(Front(&front));
}