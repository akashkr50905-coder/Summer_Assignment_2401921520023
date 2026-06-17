#include<iostream>
#include<stack>
#include <utility>   
#include <algorithm>
using namespace std;
stack<pair<int,int>>st;
void push(int val){
    if(st.empty()){
    st.push({val,val});
    }
    else{
        int min_val= min(val,st.top().second);
        st.push({val,min_val});
    }
}
void pop(){
    st.pop();
}
int top(){
    return st.top().first;
}
int getMin(){
    return st.top().second;
}
int main (){
 push(12);
 push(56);
 push(0);
cout<<"Minimum in this stack: "<< getMin()<<endl;
 push(20);
 cout<<"Now the top of the stack is: "<<top()<<endl;
 pop();
 pop();
 cout<<"Minimum in the stack: "<<getMin();
    return 0;
}