#include <iostream>

int countPath(int i, int j, int currentCost, int targetCost, int grid[4][4], int M, int N) {

    // checks if we are still within the matrix
    if (i >= M || j >= N) {
        return 0;
    }

    // to keep track of the current cost
    int newCost = currentCost + grid[i][j];

    // to end the run early if the new cost is higher than the targetCost
    if (newCost > targetCost) {
        return 0;
    }

    // one we reach the end of the matrix (M-1, N-1)
    if (i == M-1 && j == N-1) {
        if (newCost == targetCost) {
            return 1;
        }
        else {
            return 0;
        }
    }

    // recursion for movements
    int moveRight = countPath(i, j+1, newCost, targetCost, grid, M, N);
    int moveDown = countPath(i+1, j, newCost, targetCost, grid, M, N);

    // to total up all the successful paths that reached the target cost
    return moveRight + moveDown;
}

int main() {
    int M = 4;
    int N = 4;
    int targetCost = 25;

    int matrix[4][4] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int totalPaths = countPath(0, 0, 0, targetCost, matrix, M, N);

    std::cout << "Number of paths that reached the cost of " << targetCost << " with the given matrix is " << totalPaths << ".\n";

    return 0;
}