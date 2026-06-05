#include<iostream>
#include<string>
using namespace std;
bool isAlphanumeric(char ch){
   if(ch>='0'&& ch<='9'){
    return true;
   }
   if(ch>='a' && ch<='z'){
    return true;
   }
   if(ch>='A' && ch<='Z'){
    return true;
   }
   return false;
}
bool isPalindrome(string s){
    int st=0;
    int end= s.length()-1;
    while(st<end){
        if(isAlphanumeric(s[st])!=1){
            st++;
            continue;
        }
        if(isAlphanumeric(s[end])!=1){
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++;end--;
    }
    return true;
}
int main(){
    string s="A man, a plan, a canal: Panama";
    bool ans=isPalindrome(s);
    cout<<ans;
    return 0;
}