#include <iostream>
#include <map>
#include <vector>
using namespace std;

int longestSubArrXORk(vector<int>& nums,int k){
    map<int,int> myMap;
    int maxLen=0;
    int prefixXOR=0;
    for(int i=0;i<nums.size();i++){
        prefixXOR^=nums[i];
        if(prefixXOR==k){
            maxLen=i+1;
        }
        int reqXOR=prefixXOR^k;
        if(myMap.find(reqXOR)!=myMap.end()){
            int len=i-myMap[reqXOR];
            maxLen=max(maxLen,len);
        }
        if(myMap.find(prefixXOR)==myMap.end()){
            myMap[prefixXOR]=i;
        }
    }
    return maxLen;
}

int countSubArrXORk(vector<int>& nums, int k){
    map<int,int> myMap = {{0,1}};
    int count = 0;
    int prefixXOR = 0;
    for(int i = 0; i < nums.size(); i++){
        prefixXOR ^= nums[i];
        int reqXOR = prefixXOR ^ k;
        count += myMap[reqXOR]; //If reqXOR not in myMap , then myMap[reqXOR] will automatcially be 0 .
        myMap[prefixXOR]++;
    }
    return count;
}

int main(){
    vector<int> nums={4,2,2,6,4};
    int k=6;
    int maxLen=longestSubArrXORk(nums,k);
    cout<<maxLen;

    cout<<"\n";

    int count=countSubArrXORk(nums,k);
    cout<<count;
}