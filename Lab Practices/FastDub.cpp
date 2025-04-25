#include <iostream>
using namespace std;

long long fib3(int n) {
    long long i = 1, j = 0;
    long long k = 0, h = 1;
    long long t;

    while (n > 0) {
        if (n % 2 != 0) {
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
    int n;
    cout << "Enter the term to find in Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << fib3(n) << endl;

    return 0;
}
