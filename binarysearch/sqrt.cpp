#include <iostream>
using namespace std;

int sqrt(int n){
    int ans=1;
    int start=1;
    int end=n;
    while(start<=end){
        int mid=(start+end)/2;   
        if((mid*mid)<=n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return end; //or ans
}

int main(){
    int ans=sqrt(5);
    cout<<ans;
}