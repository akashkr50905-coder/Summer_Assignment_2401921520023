#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
       unordered_map<char,int> mp;
       for(char c:s){
        mp[c]++;
       }
       for(char c:t){
       if(mp[c]==0)return false;
        mp[c]--;
       }
       return true;
    }
int main(){
    string s="anagram";
    string t="nagaram";
   bool ans=isAnagram(s,t);
   cout<<ans;
    return 0;
}