#include <iostream>
using namespace std;

// Recursive function to solve knapsack problem
int knapsackRec(int W, int val[], int wt[], int n) {
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;

    // Pick nth item if it does not exceed the capacity
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    // Don't pick the nth item
    int notPick = knapsackRec(W, val, wt, n - 1);

    return max(pick, notPick);
}

// Wrapper function
int knapsack(int W, int val[], int wt[], int n) {
    return knapsackRec(W, val, wt, n);
}

int main() {
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int n = sizeof(val) / sizeof(val[0]);
    int W = 4;

    cout << knapsack(W, val, wt, n) << endl;
    return 0;
}
