#include <iostream>
#include <random>
#include "sorting.h"
#include "searching.h"
const int size = 100;
const int numCandidates = 5;

int main() {
    int dataset[size];

    std::random_device rd;
    std::mt19937 number(rd());
    std::uniform_int_distribution<int> dist(1, 5);

    for (int i = 0; i < size; i++) {
        dataset[i] = dist(number);
    }

    std::cout << "\nUnsorted Votes\n";
    for (int i = 0; i < size; i++) {
        std::cout << dataset[i] << " ";
    }

    insertionSort(dataset, size);
    std::cout << "\n\nSorted Votes\n";
    for (int i = 0; i < size; i++) {
        std::cout << dataset[i] << " ";
    }

    int counter[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        counter[i] = linearSearchArr(dataset, size, i+1);
    }

    std::string candidates[numCandidates] = {"Bo Dalton Capistrano", "Cornelius Raymon Agustin", "Deja Jayla Banaga", "Lalla Brielle Yabut", "Franklin Relano Castro"};

    std::cout << "\n\n-----Votecount-----\n";
    for (int i = 0; i < numCandidates; i++) {
        std::cout << "Candidate " << i+1 <<  ", " << candidates[i] << " = " << counter[i] << "\n";
    }

    switch (findHighest(counter, numCandidates)) {
        case 0:
            std::cout << candidates[0] << " is the winner!\n";
            break;
        case 1:
            std:: cout << candidates[1] << " is the winner!\n";
            break;
        case 2:
            std:: cout << candidates[2] << " is the winner!\n";
            break;
        case 3:
            std:: cout << candidates[3] << " is the winner!\n";
            break;
        case 4:
            std:: cout << candidates[4] << " is the winner!\n";
            break;
    }

    return 0;
}
