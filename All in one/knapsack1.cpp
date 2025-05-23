#include <iostream>
#include <algorithm>
using namespace std;

// Space-optimized bottom-up DP solution
int knapsack(int W, const int val[], const int wt[], int n) {
    int dp[W + 1] = {};

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[i]; --w) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int main() {
    const int val[] = {1, 2, 3};
    const int wt[] = {4, 5, 1};
    const int n = sizeof(val) / sizeof(val[0]);
    const int W = 4;

    cout << "Maximum value in knapsack = " << knapsack(W, val, wt, n) << endl;
    return 0;
}

