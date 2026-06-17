#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>s;
        vector<int>ans;
        unordered_map<int,int> m;
        
            for(int j=nums2.size()-1; j>=0; j--){
                while(s.size()>0 && nums2[j]>s.top()){
                    s.pop();
                }
                if(s.empty()){
                    m[nums2[j]]=-1;
       
                }else{
                    m[nums2[j]]=s.top();
                }
               s.push(nums2[j]);
            }
        for(int i=0; i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
int main(){
  vector<int>nums1={4,1,2};
  vector<int>nums2={1,3,4,2};
  vector<int>result=nextGreaterElement(nums1,nums2);
  cout<<"next greater element vector: ";
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
  }
    return 0;
}