#include<iostream>
#include<vector>
using namespace std;
 int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxwater=0;
        while(i<j){
          int ht=min(height[i],height[j]);
          int w=j-i;
          int currwater=w*ht;
          maxwater=max(maxwater,currwater);
          height[i]<height[j]? i++ : j--;
        }
        return maxwater;
    }
 int main(){
    vector<int>height={1,8,6,2,5,4,8,3,7};
    int ans=maxArea(height);
    cout<<ans;
 return 0;
 }    