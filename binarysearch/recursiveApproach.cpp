#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>arr,int start,int end,int target){
    if (start>end) return -1;
    int mid=(start+end)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
       return binarySearch(arr,start,mid-1,target);
    }
    else{
       return binarySearch(arr,mid+1,end,target);
    }
}

int main(){
    vector<int> arr={3,4,6,7,9,12,16,17};
    cout<<binarySearch(arr,0,arr.size()-1,12);
}