#include <iostream>
using namespace std;

// Function to calculate Fibonacci number using Fast Doubling method
long long fib3(long long n) {
    long long i = 1, j = 0; // F(1), F(0)
    long long k = 0, h = 1; // k and h are used in the fast doubling calculations
    long long t;

    while (n > 0) {
        if (n % 2 == 1) { // If n is odd
            t = j * h;
            j = i * h + j * k + t;  // Update Fibonacci numbers for odd n
            i = i * k + t;           // Update Fibonacci numbers for odd n
        }
        
        // Update variables for the next iteration (doubling)
        t = h * h;
        h = 2 * k * h + t; // Update h for the next Fibonacci calculation
        k = k * k + t;     // Update k for the next Fibonacci calculation
        n = n / 2;         // Half the value of n for the next step
    }

    return j; // Return the Fibonacci number at position n
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci sequence up to F(" << n << "): ";
    
    // Print Fibonacci sequence from F(0) to F(n)
    for (long long i = 0; i <= n; ++i) {
        cout << fib3(i) << " ";  // Call the fast doubling function for each index
    }

    cout << endl;  // To ensure the output ends with a new line
    return 0;
}
