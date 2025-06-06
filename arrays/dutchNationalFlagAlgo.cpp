#include <iostream>
#include <vector>
using namespace std;

void DNFAlgo(vector<int>& arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
            mid++;
        }
    }
}

int main(){
    vector<int> arr={2,0,2,1,1,0};
    DNFAlgo(arr);

    for(int val:arr){
        cout<<val<<" ";
    }
}