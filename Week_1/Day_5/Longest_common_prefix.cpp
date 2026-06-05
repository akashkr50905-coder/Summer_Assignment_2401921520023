#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        string prifix="";
       for(int i=0;i<strs[0].size();i++){
          char c=strs[0][i];
          for(int j=1;j<strs.size();j++){
            if(i>=strs[j].size() || strs[j][i]!=c){
                return prifix;
            }
          }
          prifix += c;
       }
       return prifix;
    }
int main(){
   vector<string>strs={"flower","flow","flight"};
   cout<< longestCommonPrefix(strs);
    return 0;
}