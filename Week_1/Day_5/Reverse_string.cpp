#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>& s) {
        int st=0;
        int end=s.size()-1;
        while(st<end){
            swap(s[st++],s[end--]);
        }
        for(int i=0;i<s.size();i++){
            cout<<"'"<<s[i]<<"'"<<" ";
        }
    }
int main(){
    vector<char>s={'h','e','l','l','o'};
    reverseString(s);
    return 0;
}