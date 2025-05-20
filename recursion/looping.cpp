#include <iostream>
using namespace std;

void printName(int counter,int N){
    if(counter>=N){
        return;
    }
    cout<<"Ram"<<endl;
    counter++;
    printName(counter,5);
}

int main(){
    int counter=0;
    printName(counter,5);
}

