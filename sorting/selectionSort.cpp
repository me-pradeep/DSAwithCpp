#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}

int main(){
    int arr[5]={7,4,3,6,12};
    selectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}