#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Brute-force
int longestSubArray(int target,vector<int>& arr){
    int longestSubArray=0;
    for(int i=0;i<arr.size();i++){
        int currSum=0;
        int count=0;
        for(int j=i;j<arr.size();j++){
            currSum+=arr[j];
            count++;
            if(currSum==target){
                if(count>longestSubArray){
                   longestSubArray=count; 
                }
                break;
            }
        }
    }
    return longestSubArray;
}

//Optimal approach using array-hashing format
int OptilongestSubArray(int target, vector<int>& arr){
    map<int,int> mpp;
    int maxLen=0;
    int prefixSum=0;
    for(int i=0;i<arr.size();i++){

        prefixSum+=arr[i];
        if(prefixSum==target){
            maxLen=i+1; // because 0 to 4 means 5 length , so (4+1) will give actaul length where i=4.
        }
        int reqSum=prefixSum-target;

        if(mpp.find(reqSum)!=mpp.end()){
            int len=i-mpp[reqSum];
            maxLen=max(len,maxLen);
        }

        if(mpp.find(prefixSum)==mpp.end()){ //for storing only first occurance of a particular prefixSum to get the longest sub-array possible
            mpp[prefixSum]=i;
        }
    }
    return maxLen;
}


int main(){
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    int target=3;
    cout<<longestSubArray(target,arr);
    cout<<OptilongestSubArray(target,arr);
}