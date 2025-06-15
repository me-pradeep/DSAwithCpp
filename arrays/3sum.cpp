#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//O(logn*(n^2)) time complexity approach
vector<vector<int>> triplet(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> myUniquetriplets;
    for(int i=0;i<n;i++){
        set<int> numPool;
        for(int j=i+1;j<n;j++){
            for(int k=i+1;k<j;k++){
                numPool.insert(nums[k]);
            }
            int req=-(nums[i]+nums[j]);
            if(numPool.find(req)!=numPool.end()){
                vector<int> oneTriplet={nums[i],nums[j],req};
                sort(oneTriplet.begin(),oneTriplet.end());
                myUniquetriplets.insert(oneTriplet);
            }
        }
    }
    vector<vector<int>> ans(myUniquetriplets.begin(),myUniquetriplets.end());
    return ans;
}

//
vector<vector<int>> optimalTriplet(vector<int> nums) {
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                triplets.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    return triplets;
}


int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    // vector<vector<int>> ans=triplet(nums);
    vector<vector<int>> ans=optimalTriplet(nums);

    for(vector<int> triplet:ans){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}