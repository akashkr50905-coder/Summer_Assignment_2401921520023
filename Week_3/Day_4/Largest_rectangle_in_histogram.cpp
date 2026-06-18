#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    int largestRectangleArea(vector<int>& ht) {
        int maxArea= 0;
        stack<int>s;
        vector<int>right(ht.size(),0);
        vector<int>left(ht.size(),0);
       
        for(int i=ht.size()-1;i>=0;i--){
            while(s.size()>0 && ht[s.top()]>=ht[i]){
                s.pop();
            }
             if(s.empty()){
                right[i]=ht.size();
             }else{
                right[i]=s.top();
             }
             s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<ht.size();i++){
            while(s.size()>0 && ht[s.top()]>=ht[i]){
                s.pop();
            }
             if(s.empty()){
                 left[i]=-1;
             }else{
                 left[i]=s.top();
             }
             s.push(i);
        }
        for(int i=0;i<ht.size();i++){
            int width=right[i]-left[i]-1;
            int currArea = ht[i] * width;
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
int main(){
vector<int>ht={2,1,5,6,2,3};
 cout<<" Area of the largest rectangle is: "<<largestRectangleArea(ht);
    return 0;
}