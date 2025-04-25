#include <iostream>
using namespace std;

int fib2(int n) {
    int i = 1, j = 0;
    for (int k = 1; k <= n; ++k) {
        j = i + j;
        i = j - i;
    }
    return j;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci sequence up to position " << n << ": ";
    for (int i = 0; i <= n; ++i) {
        cout << fib2(i) << " ";
    }
    return 0;
}
