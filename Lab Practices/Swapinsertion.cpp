#include<iostream>
  using namespace std;

  void Insertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;

        while(j>0 && arr[j]<arr[j-1]){
            int temp =arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
  }
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[]={5,6,3,2,6,4};
    int n= sizeof(arr)/sizeof(arr[0]);

    Insertion(arr,n);
    cout<<"Sorted Array: ";
    printArray(arr,n);

    return 0;
}