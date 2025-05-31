#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//brute-force approach
vector<int> getUnion(vector<int>& arr1 , vector<int>& arr2){
    vector<int> ans;
    set<int> set1;
    for(int val:arr1){
        set1.insert(val);
    }
    for(int val:arr2){
        set1.insert(val);
    }
    for(int val:set1){
        ans.push_back(val);
    }
    return ans;
}

//optimal approach
vector<int> optimalGetUnion(vector<int>& arr1 , vector<int>& arr2){
    vector<int> ans;
    int ind1=0;
    int ind2=0;

    int size1=arr1.size();
    int size2=arr2.size();

    while(ind1<size1 && ind2<size2){
        if(arr1[ind1]<=arr2[ind2]){
            if(ans.size()==0 || ans.back()!=arr1[ind1]){
                ans.push_back(arr1[ind1]);
            }
            ind1++;
        }
        else{
            if(ans.size()==0 || ans.back()!=arr2[ind2]){
                ans.push_back(arr2[ind2]);
            }
            ind2++;
        }
    }
    while (ind1 < size1) {
        if (ans.empty() || ans.back() != arr1[ind1])
            ans.push_back(arr1[ind1]);
        ind1++;
    }

    while (ind2 < size2) {
        if (ans.empty() || ans.back() != arr2[ind2])
            ans.push_back(arr2[ind2]);
        ind2++;
    }
    return ans;
}


int main(){
    vector<int> arr1={1,1,2,3,4,5};
    vector<int> arr2={2,3,4,4,5,6};

    vector<int>ans=optimalGetUnion(arr1,arr2);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}