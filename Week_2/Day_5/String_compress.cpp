#include<iostream>
#include<string>
#include<vector>
using namespace std;
int compress(vector<char>& chars) {
        int idx=0;
        for(int i=0;i<chars.size();i++){
            char ch= chars[i];
            int count=0;
            while(i<chars.size()&& ch==chars[i]){
                count++;i++;
            }
            if(count==1){
                chars[idx++]=ch;
            }
            else{
                chars[idx++]=ch;
                string str=to_string(count);
                for(int i=0;i<str.length();i++){
                    chars[idx++]=str[i];
                }
            }
            i--;
        }
        chars.resize(idx);
       return idx;
    }
int main(){
  vector<char> chars={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
  cout<<"After compressing the size of chars is: "<<compress(chars);
    return 0;
}    