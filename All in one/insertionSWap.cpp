#include <iostream>
using namespace std;

// Function to perform Insertion Sort using Swapping
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;

        // Keep swapping arr[j] with arr[j-1] until arr[j] is in correct position
        while (j > 0 && arr[j] < arr[j - 1]) {
            // Swap arr[j] and arr[j-1]
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            // Move one position back
            j--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test the sorting
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
