#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr,int target){
    int LB=arr.size();//.i.e. not found any lower_bound
    int start=0;
    int end=arr.size()-1;

    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]>=target){
            LB=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return LB;
}

int upperBound(vector<int>& arr,int target){
    int UB=arr.size();//.i.e. not found any upper_bound
    int start=0;
    int end=arr.size()-1;

    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]>target){
            UB=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return UB;
}

int main(){
    vector<int> arr={3,5,8,15,19};
    int LB=lowerBound(arr,8);
    int UB=upperBound(arr,8);
    cout<<LB<<UB;
}