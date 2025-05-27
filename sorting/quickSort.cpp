#include <iostream>
using namespace std;

int partition(int arr[],int st, int end){
    int pivot=arr[end],idx=st-1;
    for(int j=st;j<=end-1;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx],arr[j]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quickSort(int arr[],int st, int end){
    if(st<end){
        int pivIdx=partition(arr,st,end);
        quickSort(arr,st,pivIdx-1);
        quickSort(arr,pivIdx+1,end);
    }
}

int main(){
    int arr[6]={5,2,6,4,1,3};
    quickSort(arr,0,5);

    for(int val:arr){
        cout<<val<<" ";
    }
}