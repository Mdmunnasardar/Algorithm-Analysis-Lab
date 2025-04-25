#include <iostream>
using namespace std;

long fib_recursive(long n) {
    if (n == 0) return 0;   
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2); 
}

int main() {
    long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci sequence up to F(" << n << "): ";
    
    for (long i = 0; i <= n; ++i) {
        cout << fib_recursive(i) << " ";  
    }
    return 0;
}
