#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int low ,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return;
}

void divide_arr(vector<int> &arr,int low ,int high){
    if(low<high){
        int mid=(low+high)/2;
        divide_arr(arr,low,mid);
        divide_arr(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    else{
        return;
    }
}

int main(){
    vector<int> arr={4,5,6,4,3};
    divide_arr(arr,0,4);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}