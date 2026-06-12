#include<iostream>
#include<string>
using namespace std;
  bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
       int max_len=0;
       string ans="";
        for(int i=0;i<s.length();i++){
             for(int j = s.length()-1; j >= i; j--){

                if(s[i] == s[j] && isPalindrome(i,j,s)){
                  int len= j-i+1;
                  if(len> max_len){
                    max_len= len;
                    ans= s.substr(i,len);
                  }
                }
            }
        }
        
        return ans;
    }
    int main(){
        string s="babad";
       string result= longestPalindrome(s);
       cout<<""<<result;
        return 0;
    }