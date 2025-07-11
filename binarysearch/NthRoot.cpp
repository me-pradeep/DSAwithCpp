#include <iostream>
using namespace std;

int calculate(int p , int num,int k){ 
    //see basically we are not using pow() functions..because let say p =10 and num=10^9 , then it will be 10^90 and we can't store it..so we are using this way
    // , where we jsut checking if ans==k or ans>k or ans<k ..and that's what we actually want for binary search in nthRoot function below.
    long long ans=1;
    for(int i=0;i<p;i++){
        ans=ans*num;
        if(ans>k){
            return 2;
        }
    }
    if(ans==k)return 1;
    return 0;
}
int nthRoot(int n , int k){
    int start=1;
    int end=k;
    while(start<=end){
        int mid=(start+end)/2;
        int check=calculate(n,mid,k);
        if(check==1){
            return mid;
        }
        else if(check==0){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int ans=nthRoot(3,27);
    cout<<ans;
}