#include<iostream>
#include<string>
using namespace std;
bool isfreqSame(int freq[],int windowFreq[]){
    for(int i=0;i<26;i++){
        if(freq[i]==windowFreq[i]){
            return true;
        }
        return false;
    }
}
bool isPermutationInString(string s1,string s2){
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    int windowSize=s1.length();
    for(int i=0;i<s2.length();i++){
       int windowFreq[26]={0};
       int windowidx=0;
       int idx=i;
       while(windowidx<s1.length() && idx<s2.length()){
        windowFreq[s2[idx]-'a']++;
        windowidx++;idx++;
       }
       if(isfreqSame(freq,windowFreq)){
        return true;
       }
       
    }
    return false;
    
}
int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool ans= isPermutationInString(s1,s2);
    cout<< ans;
    return 0;
}