#include<bits/stdc++.h>
using namespace std;

class Solution {
  vector<vector<bool>>visited;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  int count = 0;
  void dfs(int x,int y,vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    visited[x][y] = true;
     count++;
    for(int i = 0;i<4;i++){
      int newx = x + dx[i];
      int newy = y + dy[i];
      if(newx >=0 && newy >= 0 && newx < m && newy < n && !visited[newx][newy] && grid[newx][newy] == 1){
        dfs(newx,newy,grid);
      }
    }
  }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      visited = vector<vector<bool>> (m,vector<bool>(n)) ;
      for(int i = 0;i<m;i++){
        for(int j = 0;j < n;j++){
          if(grid[i][j] == 1 && !visited[i][j])
          count = 0;
          dfs(i,j,grid);
          
        }
      }
      return count;
    }
};