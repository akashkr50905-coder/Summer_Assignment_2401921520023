#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int st_row=0;
        int st_col=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int total_ele=m*n;
        while(st_row<=m && st_col<=n){
           if(ans.size()<total_ele){
                for(int j=st_col;j<=n-1;j++){
                    ans.push_back(matrix[st_row][j]);
                }
           }  
             if(ans.size()<total_ele){
                    for(int i=st_row+1;i<=m-1;i++){
                       ans.push_back(matrix[i][n-1]);
                    }
             }   
             if(ans.size()<total_ele){
                for(int j=n-1-1;j>=st_col;j--){
                   ans.push_back(matrix[m-1][j]);
                }
             }
             if(ans.size()<total_ele){
                for(int i=m-1-1;i>=st_row+1;i--){
                    ans.push_back(matrix[i][st_col]);
                 }
             }
           st_row++;n--;m--;st_col++;
        }
        return ans;
    }
int main(){
   vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
   vector<int>ans=spiralOrder(matrix);
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
}