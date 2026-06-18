#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        vector<int>ans(temp.size());
        for(int i=temp.size()-1;i>=0;i--){
           
         while(st.size()>0 && st.top().first<=temp[i]){
                st.pop();
            }
             if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top().second-i;
            }
            st.push({temp[i],i});
        }
      
       return ans;
 }
int main(){
    vector<int> temp={73,74,75,71,72,72,76,73};
  vector<int>result=dailyTemperatures(temp);
  for(int i=0;i<temp.size();i++){
    cout<<result[i]<<" ";
  }
    return 0;
}