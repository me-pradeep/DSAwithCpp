#include <iostream>
#include <vector>
using namespace std;

int merge(int arr[],int start,int mid,int end){
    int count=0;
    int ind1=start;
    int ind2=mid+1;
    vector<int> temp={};
    while(ind1<=mid && ind2<=end){
        if(arr[ind1]>arr[ind2]){
            count+=((mid-ind1)+1);
            temp.push_back(arr[ind2]);
            ind2++;
        }
        else{
            temp.push_back(arr[ind1]);
            ind1++;
        }
    }
    while(ind1<=mid){
        temp.push_back(arr[ind1]);
        ind1++;
    }
    while(ind2<=end){
        temp.push_back(arr[ind2]);
        ind2++;
    }
    for(int i=0;i<temp.size();i++){
        arr[start+i]=temp[i];
    }
    return count;
}

int divide(int arr[],int start,int end){
    if (start >= end)
        return 0;

    int mid=(start+end)/2;

    int count1=divide(arr,start,mid);
    int count2=divide(arr,mid+1,end);
    int count3=merge(arr,start,mid,end);
    return count1+count2+count3;
}


int countInversion(int arr[],int size){
    return divide(arr,0,size-1);
}

int main(){
    int arr[]={5,3,2,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=countInversion(arr,n);
    cout<<ans;
}