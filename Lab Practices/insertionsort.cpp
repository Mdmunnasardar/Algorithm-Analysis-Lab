#include<iostream>
  using namespace std;

void Insertionsort(int arr[],int n){
    for (int i=1;i<n;++i){
        int key= arr[i];
        int j=i-1;

    while (j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        --j;

    }
    arr[j+1]=key;
    }

}

void PrintArray(int arr[],int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    }


    int main (){
        int arr[]={4,5,2,6,5,3};
        int n=sizeof(arr)/sizeof(arr[0]);

        Insertionsort(arr,n);
        cout<<"Sorted Array: ";

        PrintArray(arr,n);

        return 0;
    }