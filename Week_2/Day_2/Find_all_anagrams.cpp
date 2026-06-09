#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
   vector<int> findAnagrams(string s, string p) {
       
        vector<int> result;
        if(s.length() < p.length()) return result;

        unordered_map<char, int> freqMap;
        unordered_map<char, int> windowMap;

        for(char c : p){
            freqMap[c]++;
        }

        int windsize = p.length();
        for(int i = 0; i < windsize; i++){
            windowMap[s[i]]++;
        }
        if(freqMap == windowMap) result.push_back(0);
        
        for(int i = windsize; i < s.length(); i++){
            windowMap[s[i]]++;

            char leftChar = s[i - windsize];
            windowMap[leftChar]--;
            if(windowMap[leftChar] == 0){
                windowMap.erase(leftChar); 
            }

            if(freqMap == windowMap){
                result.push_back(i - windsize + 1);
            }
        }

        return result;
    }
int main(){
     string s = "cbaebabacd"; 
     string p = "abc";
     vector<int>ans= findAnagrams(s,p); 
     cout<<"[";
     for(int val:ans){
        cout<<val<<" ";
     }
     cout<<"]";
    return 0;
}