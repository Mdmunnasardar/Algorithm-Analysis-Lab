#include <iostream>
using namespace std;

long long fib_recursive(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") = " << fib_recursive(n) << endl;
    return 0;
}
