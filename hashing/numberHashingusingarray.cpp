#include <iostream>
using namespace std;

int main(){
    int N;//size of array
    cin>>N;

    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    //Precomputation:- Our Hash array having size to be "highest element of given array +1"
    int hash[13]={0};
    for(int i=0;i<N;i++){
       hash[arr[i]]+=1; 
    }

    int k;//for how many elements of given array you want to count their accorance?
    cin>>k;

    while(k--){
        int e;
        cin>>e;
        cout<<hash[e]<<endl;//fetching
    }
}