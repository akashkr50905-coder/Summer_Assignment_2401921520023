#include<iostream>
#include<vector>
using namespace std;
vector<int>squares_of_sorted_arr(vector<int>&nums){
    vector<int>ans(nums.size(),0);
    int left=0;
    int right=nums.size()-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(abs(nums[left])>abs(nums[right])){
            ans[i]=nums[left]*nums[left];
            left++;
        }
        else if(abs(nums[left])<abs(nums[right])){
            ans[i]=nums[right]*nums[right];
            right--;
        }
    }
    return ans;
}
int main(){
    vector<int>nums={-4,-1,0,3,10};
    vector<int>ans=squares_of_sorted_arr(nums);
    for(int i=0;i<nums.size();i++){
        cout<<" "<<ans[i];
    }
}