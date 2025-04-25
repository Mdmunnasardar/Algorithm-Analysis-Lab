#include <iostream>
using namespace std;

int fib(int n)
{
    int i = 1, j = 0;
    for (int k = 1; k <= n; ++k)
    {
        j = i + j;
        i = j - i;
    }
    return j;
}

int main()
{
    int n;

    cout << "Enter the number: " << endl;
    cin >> n;

    cout << "The  Fibonacci number is of " <<n<<"th position : " << fib(n)<<endl;

    cout << "The Sequnce of the Fibonacci : ";

    for (int i = 0; i < n; ++i)
    {
        cout << fib(i) << " ";
    }
    return 0;
}