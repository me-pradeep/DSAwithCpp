#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapHappen=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapHappen=true;
            }
        }
        if(!swapHappen){
            break;
        }
    }
}

int main(){
    int arr[5]={1,0,5,7,3};
    bubbleSort(arr,5);

    for(int val:arr){
        cout<<val<<" ";
    }
    return 0;
}