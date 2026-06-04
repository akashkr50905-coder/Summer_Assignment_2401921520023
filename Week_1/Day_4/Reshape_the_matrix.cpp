#include<iostream>
#include<vector>
using namespace std;
 vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       vector<vector<int>>ans(r, vector<int>(c,0));
       vector<int>store_mat;
        if(mat.size()*mat[0].size()==r*c){     //legal;
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                   store_mat.push_back(mat[i][j]);
                }
            }
            int idx=0;
            for(int row=0;row<r;row++){
                for(int col=0;col<c;col++){
                    ans[row][col]=store_mat[idx++];
                }
            }
            return ans;
        }
        return mat;    //illegal;
    }
int main(){
  vector<vector<int>>mat={{1,2},{3,4}};
  int r=1;
  int c=4;
  vector<vector<int>>ans=matrixReshape(mat,r,c);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}