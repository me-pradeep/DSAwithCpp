#include <iostream>
#include <vector>
using namespace std;

vector<int> leaderInArray(vector<int>& nums){
    vector<int> ans;
    int max=INT_MIN;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>max){
            ans.push_back(nums[i]);
        }
        if(nums[i]>max){
            max=nums[i];
        }
    }
    return ans;
}

int main(){
    vector<int> nums={10,22,12,3,0,6};
    vector<int> ans=leaderInArray(nums);
    for(int val:ans){
        cout<<val<<" ";
    }
    return 0;
}