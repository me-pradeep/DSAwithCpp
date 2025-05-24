#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        arr[i]=num;
    }

    //Precomputing
    map<int,int> mpp;
    for(int i=0;i<N;i++){
        mpp[arr[i]]=mpp[arr[i]]+1;
    }

    int k;
    cin>>k;

    while(k--){
        int e;
        cin>>e;
        cout<<mpp[e]<<endl;
    }

    return 0;
}