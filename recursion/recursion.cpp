#include <iostream>
using namespace std;

//Tail Recurison
void printNto1(int i,int N){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    printNto1(i-1,N);
}

int main(){
    int counter=5;
    printNto1(counter,5);
    return 0;
}

Head Recurison
void printNto1b(int i,int N){
    if(i>N){
        return;
    }
    printNto1b(i+1,N);
    cout<<i<<endl;
}
 
// int main(){
//     int counter=1;
//     printNto1b(counter,5);

//     return 0;
// }