#include<iostream>
#include<string>
using namespace std;
bool isSubsequence(string s, string t) {
         int i=0;
         int j=0;
         int idx=0;
            while(j<s.length() && idx<t.length()){
                if(s[i]==t[idx]){
                    j++;i++;
                }
                idx++;
            }
            if(j==s.length()){
                return true;
            }
            else{
                return false;
            }
        
    }
int main(){
string s="abc"; 
string t="ahbgdc";
bool ans=isSubsequence(s,t);
cout<<"if 's' is a subsequence of 't': "<<ans;
    return 0;
}