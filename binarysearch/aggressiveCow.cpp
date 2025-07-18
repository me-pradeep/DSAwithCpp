#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& arr,int minDis,int k){
    int n=arr.size();
    int count=1;
    int lastCowPos=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastCowPos>=minDis){
            count++;
            lastCowPos=arr[i];
        }
        if(count==k){
            return true;
        }
    }
    return false;
}


int aggressiveCow(vector<int>& arr,int k){
    //here range of possible minimum distance between cows is 1 to arr[n-1]-arr[0]
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int start=1;
    int end=arr[n-1]-arr[0];

    while(start<=end){
        int mid=(start+end)/2;

        bool check=isValid(arr,mid,k);
        if(check){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return end;
}

int main(){
    vector<int> arr={0,3,4,7,9,10};
    int ans=aggressiveCow(arr,4);
    cout<<ans;
}