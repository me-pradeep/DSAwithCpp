#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Palindrome(string s){
    string res="";
    int len=s.size();
    for(int i=0;i<len;i++){
        char ch=s[i];
        bool isAlphanumeric=(
            (ch>='A' && ch<='Z')||
            (ch>='a' && ch<='z')||
            (ch>='0' && ch<='9')
        );
        if(isAlphanumeric){
           if(ch>='A' && ch<='Z'){
            ch=ch+32;
           }
           res=res+ch;
        }
    }
    string reversed=res;
    reverse(reversed.begin(),reversed.end());
    if(reversed==res){
        return true;
    }
    return false;
}

int main(){
    cout<<Palindrome("A man, a plan, a canal: Panama");
    return 0;
}