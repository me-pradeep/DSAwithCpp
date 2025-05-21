#include <iostream>
using namespace std;

void printName(int counter,int N){
    if(counter>N){
        return;
    }
    cout<<"Ram"<<endl;
    printName(counter+1,5);
}

int main(){
    int counter=1;
    printName(counter,5);
}

