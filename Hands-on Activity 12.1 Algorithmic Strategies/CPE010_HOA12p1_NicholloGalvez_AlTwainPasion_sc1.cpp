#include <iostream>
#include <algorithm>

using namespace std;

//limit value
const int MAX_N = 100;
int memo[MAX_N + 1];

int getMinSteps(int n) {
    if (n == 1) return 0; 
    if (memo[n] != -1) return memo[n]; 

    int r = 1 + getMinSteps(n - 1); 
    if (n % 2 == 0) r = min(r, 1 + getMinSteps(n / 2)); 
    if (n % 3 == 0) r = min(r, 1 + getMinSteps(n / 3)); 

    memo[n] = r; 
    return r;
}

int main() {
    int n = 10;

    fill(memo, memo + MAX_N + 1, -1);

    cout << "Minimum steps for " << n << " is: " << getMinSteps(n) << endl;

    return 0;
}