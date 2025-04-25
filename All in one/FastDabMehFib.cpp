#include <iostream>
using namespace std;

long long fib3(long long n) {
    long long i = 1, j = 0; // F(1), F(0)
    long long k = 0, h = 1;
    long long t;

    while (n > 0) {
        if (n % 2 == 1) { // if n is odd
            t = j * h;
            j = i * h + j * k + t;
            i = i * k + t;
        }
        t = h * h;
        h = 2 * k * h + t;
        k = k * k + t;
        n = n / 2;
    }

    return j;
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") = " << fib3(n) << endl;
    return 0;
}
