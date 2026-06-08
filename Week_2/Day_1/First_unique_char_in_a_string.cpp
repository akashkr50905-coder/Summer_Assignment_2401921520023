#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
int firstUniqChar(string s) {
        queue<int>q;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                q.push(i);
                m[s[i]]++;
            }
            else{
                m[s[i]]++;
            }
        }
        while(q.size()>0&& m[s[q.front()]]>1){
            q.pop();
        }
        return q.empty() ? -1: q.front();
    }
int main() {
    string s="akash";
    int ans=firstUniqChar(s);
    cout<<"The index of first unique char is: "<<ans;
    return 0;
}   