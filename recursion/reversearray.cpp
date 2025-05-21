#include <iostream>
using namespace std;

void reverse(int arr[],int counter,int len){
    if(counter>len/2){
       return; 
    }
    swap(arr[counter-1],arr[len-counter]);
    return reverse(arr,counter+1,len);
}
int main(){
    int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,1,len);

    for(int i=0;i<len;i++){
        cout<<arr[i];
    }
}