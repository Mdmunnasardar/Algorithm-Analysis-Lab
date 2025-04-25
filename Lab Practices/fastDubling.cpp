#include<iostream>
 using namespace std;

 int fib(int n){
    int i=1,j=0;
    int k=0,h=1;
    int t;

    while(n>0){
        if(n%2==1){
            t=j*h;
            j=i*h+j*k+t;
            i=i*k+t;
        }
            t=h*h;
            h=2*h*k+t;
            k=k*k+t;
            n=n/2;
    }
    return j;

 }

 int main(){
    int n;
     cout<<"Enter the number: "<<endl;
    cin>>n;

    cout<<"Fibonacci number is : "<<fib(n);


    return 0;
 }