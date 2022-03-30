#include<bits/stdc++.h>
using namespace std;

class Solution {
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  int count = 0;
  void dfs(int x,int y,vector<vector<int>>& grid{
    int m = grid.size();
    int n = grid[0].size();
    grid[x][y] = 0;
    for(int i = 0;i<m;++i){
      for(int j = 0;j<n;++j){
        int newx = x + dx[i];
        int newy = y + dy[i];
         if(x>=0 && y>=0 && x<m && y<n && grid[newx][newy] == 1){
           dfs(i,j,grid);
         }
      }
    }
  }
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       for(int i = 0;i<m;++i){
         for(int j = 0;j<n;++j){
           if(grid[i][j] == 1 && (i == 0 || j == 0 || i = m-1 || j = n-1)){
             dfs(i,j,grid);
           }else if(grid[i][j] == 1){
             count++;
           }
         }
       }
       return count;
    }
};