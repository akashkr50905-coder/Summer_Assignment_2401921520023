#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
       for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&& tokens[i]!="-"&& tokens[i]!="/"&& tokens[i]!="*"){
                st.push(stoi(tokens[i]));
            }
            else{
                if(tokens[i]=="+"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b+a);
                }
                if(tokens[i]=="*"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b*a);
                }
                if(tokens[i]=="/"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b/a);
                }
                if(tokens[i]=="-"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b-a);
                }
            }
       }
       return st.top();
    }
int main(){
  vector<string>tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
 cout<<"Result of RPN is: "<<evalRPN(tokens);
    return 0;
}