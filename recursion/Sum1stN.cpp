#include <iostream>
using namespace std;

int sum(int N){
    if(N==0){
        return 0;
    }
    return N+sum(N-1);
}

int main(){
    cout<<sum(120);
    return 0;
}