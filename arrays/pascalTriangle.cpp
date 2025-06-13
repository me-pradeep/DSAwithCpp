#include <iostream>
#include <vector>
using namespace std;

int pascalNumber(int Row, int Col){
    int r=Row-1;
    int c=Col-1;
    int num=1;
    int den=1;
    for(int i=1;i<=c;i++){
        num*=(r-(i-1));
        den*=i;
    }
    return num/den;
}

vector<int> pascalRow(int Row){
    vector<int> ans;
    long long myVar=1;
    for(int i=0;i<Row;i++){
        ans.push_back(myVar);
        myVar=myVar * (Row - i - 1) / (i + 1);
    }
    return ans;
}

int main(){
    int pascalNum=pascalNumber(5,3);
    vector<int> mypascalRow=pascalRow(6);
    for(int val:mypascalRow){
        cout<<val<<" ";
    }
    cout<<"\n";
    cout<<pascalNum;
    return 0;
}