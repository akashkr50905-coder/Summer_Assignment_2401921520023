#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
 bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char c: magazine){
            mp[c]++;
        }
        for(char c: ransomNote){
            if(mp.find(c)!= mp.end()){
               if(mp[c]==0)return false;
                mp[c]--;
                continue;
            }
            else {
                return false;
                }
        }
        return true;
    }
int main(){
    string ransomNote="aa";
    string magazine="aab";
   cout<<canConstruct(ransomNote,magazine);
    return 0;
}