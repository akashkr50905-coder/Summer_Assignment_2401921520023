#include<iostream>
#include<stack>
using namespace std;
    stack<int> s1;
    stack<int> s2;
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            return;
        }
        else{
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            }
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }
        else{
            int ans=s1.top();
            s1.pop();
            return ans;
        }
    }
    
    int peek() {
        if(s1.empty()){
            return -1;
        }
        else{
            return s1.top();
        }
    }
    
    bool empty() {
        return s1.empty();
    }
    int main(){
        push(1);
        push(2);
       cout<< peek()<<endl;
       cout<< pop()<<endl;
        push(10);
        push(34);
        cout<< pop()<<endl;
        cout<<empty()<<endl;
         cout<< pop()<<endl;
         cout<< pop()<<endl;
         cout<< peek()<<endl;
         cout<< empty()<<endl;
        return 0;
    }