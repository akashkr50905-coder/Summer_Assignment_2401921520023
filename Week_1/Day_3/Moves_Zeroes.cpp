#include<iostream>
#include<vector>
using namespace std;
vector<int> moves_zeroes(vector<int>&nums){
       int left=0;

    for(int right=0;right<nums.size();right++){

        if(nums[right]!=0){
            swap(nums[left],nums[right]);
            left++;
        }
        
    }
  return nums;
}
int main(){
    vector<int>nums={0,1,0,3,12};
   vector<int>ans= moves_zeroes(nums);
   for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
   }
  return 0;
}