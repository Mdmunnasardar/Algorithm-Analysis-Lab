#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n - 1, answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            answer = mid;  // possible answer, but keep going left
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int arr[] = {2, 4, 4, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    int result = lowerBound(arr, n, target);

    if (result != -1)
         cout << "Element found at index " << result 
             << " with value " << arr[result] << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
