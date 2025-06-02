#include <iostream>
#include <vector>
using namespace std;

vector<int> getIntersection(vector<int>& arr1, vector<int>& arr2){
    vector<int> ans;
    int size1=arr1.size();
    int size2=arr2.size();
    int ind1=0;
    int ind2=0;

    while(ind1<size1 && ind2<size2){
        if(arr1[ind1]>arr2[ind2]){
            ind2++;
        }
        else if(arr2[ind2]>arr1[ind1]){
            ind1++;
        }
        else{
            if(ans.empty() || ans.back()!=arr1[ind1]){
                ans.push_back(arr1[ind1]);
            }
            ind1++;
            ind2++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr1={1,1,2,3,4,5};
    vector<int> arr2={2,3,4,4,5,6};

    vector<int>ans=getIntersection(arr1,arr2);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}