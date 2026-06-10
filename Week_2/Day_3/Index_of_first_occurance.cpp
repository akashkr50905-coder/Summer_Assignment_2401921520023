#include<iostream>
#include<string>
using namespace std;
    int indexOfFirstOcc(string haystack, string needle) {
      if(haystack.length()<needle.length())return -1;  
        for(int i=0;i<=haystack.length()-needle.length();i++){
            int j=0;
            while(j<needle.length() && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==needle.length())return i;
        }
         return -1;
    }

int main(){
    string haystack="sadbutsad";
    string needle="sad";
    int ans= indexOfFirstOcc(haystack,needle);
    cout<<"index of first occurance is: "<<ans;
    return 0;
}