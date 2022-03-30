#include<bits/stdc++.h>
using namespace std;

class Solution {
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  int count = 0;
  bool isPossible = true;
  void dfs(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
    int m = grid1.size();
    int n = grid1[0].size();
    for(int i = 0;i<4;++i){
      int newx = x + dx[i];
      int newy = y + dy[i];
      if(newx>=0 && newy>=0 && newx < m && newy<n && grid2[newx][newy] == 1){
        if(grid1[newx][newy] == 0) {
          isPossible = false;
          return;
        }
        dfs(newx,newy,grid1,grid2);
      }
    }
  }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        for(int i = 0;i<m;++i){
          for(int j = 0;j<n;++j){
            if(grid2[i][j] == 1 && grid1[i][j] == 1){
              dfs(i,j,grid1,grid2);
              if(isPossible){ 
              count++;
              isPossible = true;}
            }
          }
        }
    }
};