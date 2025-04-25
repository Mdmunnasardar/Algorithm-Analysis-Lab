#include<iostream>
  using namespace std ;

  int fib(int n){
  int i=1,j=0;
  int h=1,k=0;
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

int main (){
    int n ;

    cout<<" Enter the number: ";
    cin>>n;

    cout<<"Fibonacci number is : "<<fib(n)<<endl;

    cout<<"The Sequence ot the fibonacci : ";

    for(int i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }
}