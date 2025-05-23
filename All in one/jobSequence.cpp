#include <iostream>
#include <algorithm>
using namespace std;

// Job structure
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit of job
};

// Compare jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs and return max profit
void jobSequencing(Job jobs[], int n) {
    // Step 1: Sort jobs by decreasing profit
    sort(jobs, jobs + n, compare);

    // Step 2: Find max deadline to create time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    // Step 3: Create time slots and initialize to -1
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int countJobs = 0, totalProfit = 0;

    // Step 4: Try to fit each job into a free slot
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output the result
    cout << "Total Jobs Done: " << countJobs << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}
