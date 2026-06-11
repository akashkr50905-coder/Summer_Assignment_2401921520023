#include<iostream>
#include<string>
using namespace std;
 string reverse(int left,int right,string &s){
    while(left<right){
        swap(s[left],s[right]);
        left++;right--;
    }
    return s;
}
string reverseWords(string &s, int left, int right){
    while(s[right+1]!=' '&& right!=s.length()-1){
        right++;
    }
    if(s[right+1]==' '|| right==s.length()-1){
        reverse(left,right,s);
        if(right!=s.length()-1){
            reverseWords(s,right+2,right+2);
        }
    }
    
    return s;
}
    
int main(){
    string s= "Let's take LeetCode contest";
    int left=0;
    int right=0;
    reverseWords(s,left,right);
    cout<<s;
    return 0;
}