#include<iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return fib(n-1)+fib(n-2);
    }
}

int main (){
    int n;
    cout<<"enter the nuber: ";
    cin>>n;
    cout<<" the fibonacci number is : "<<fib(n)<<endl;

    return 0;
}