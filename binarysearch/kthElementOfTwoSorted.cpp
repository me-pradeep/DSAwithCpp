#include <iostream>
#include <vector>
using namespace std;

bool isValid(int l1 , int l2 , int r1 , int r2){
    if(l1<=r2 && l2<=r1){
        return true;
    }
    return false;
}

int kthElem( vector<int> &vec1 , vector<int> &vec2 , int k){
    int n=vec1.size();
    int m=vec2.size();
    int total=m+n;
    
    if(k < 1 || k > total) {
        return -1;
    }

    if(n > m){
        return kthElem( vec2 , vec1 , k);
    }

    int start = max(0, k-m); // Can't take less than (k-m) from first array , because if i need k and arr2 have only m , then arr1 should min give k-m
    int end = min(k,n);      // Can't take more than k or n from first array 

    while(start<=end){
        int mid = (start+end)/2;
        int reqFromOthArr= k - mid;

        int l1=INT_MIN , l2=INT_MIN;
        int r1=INT_MAX , r2=INT_MAX;

        if(mid>0)l1=vec1[mid-1];
        if(reqFromOthArr>0)l2=vec2[reqFromOthArr-1];

        if(mid<n)r1=vec1[mid];
        if(reqFromOthArr<m)r2=vec2[reqFromOthArr];

        bool check=isValid(l1,l2,r1,r2);

        if(check){
            return max(l1,l2);
        }else if(l1>r2){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec1={2,3,6,7,9};
    vector<int> vec2={1,4,8,10};
    
    cout << kthElem(vec1,vec2 , 5);

}