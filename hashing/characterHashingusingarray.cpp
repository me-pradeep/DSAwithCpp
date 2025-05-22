#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    //Precomputation:- Our Hash array having size such that highest possible character of given string, occurance can be count"
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]+=1; //s[i] is a character but index is integer so charcter will convert into it's ASCII value
    }

    int k;//for how many characters of given string you want to count their accorance?
    cin>>k;

    while(k--){
        char e;
        cin>>e;
        cout<<hash[e]<<endl;//fetching
    }
}