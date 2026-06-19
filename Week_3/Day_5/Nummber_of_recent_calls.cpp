#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
 int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000){  // remove requests outside the window
            q.pop();
        }
        return q.size();
    }
int main(){
cout<<ping(1)<<endl;
cout<<ping(1000)<<endl; 
cout<<ping(3003)<<endl; 
cout<<ping(3001);
    return 0;
}