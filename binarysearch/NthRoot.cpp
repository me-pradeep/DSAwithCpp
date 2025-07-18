#include <iostream>
#include <vector>
using namespace std;


int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            //2 3 4 7 11 (arr)
            //1 1 1 3 6 (arr[i]-(i+1))

            //1 2 3 4 (arr)
            //0 0 0 0 (arr[i]-(i+1))
            int missingCount=arr[mid]-(mid+1);
            if(missingCount>=k){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start+k;
}

int main(){
    vector<int> arr={2,3,4,7,11};
    int ans=findKthPositive(arr,5);
    cout<<ans;
}