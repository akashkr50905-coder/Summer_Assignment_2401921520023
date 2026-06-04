#include<iostream>
#include<vector>
using namespace std;
 int diagonalSum(vector<vector<int>>& mat) {
        int prim_sum=0;
        int sec_sum=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(i==j){
                    prim_sum+=mat[i][j];     //primary dig sum.
                }
                if((i+j)==mat.size()-1 && (i!=j)){
                    sec_sum+=mat[i][j];     //secondary dig sum.
                }
            }
        }
        int sum= prim_sum + sec_sum; 
        return sum;
    }
 int main(){
    vector<vector<int>>mat= {{1,2,3}, {4,5,6},{7,8,9}};
    int Diagonal_sum=diagonalSum(mat);
    cout<<Diagonal_sum<<endl;
    return 0;
 }