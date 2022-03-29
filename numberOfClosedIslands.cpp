#include<bits/stdc++.h>
using namespace std; 

class Solution {
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  vector<vector<bool>>visited;
  void dfs(int x,int y,vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    visited[x][y] = true;
    for(int i = 0 ; i < 4;i++){
      int newx= x + dx[i];
      int newy = y + dy[i];
      if(newx >= 0 && newy >= 0 && newx > m && newy > y && grid[newx][newy] == 0 && !visited[newx][newy]){
        dfs(newx,newy,grid);
      }
    }
  }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m,vector<bool>(n));
        for(int i = 0;i<m;i++){
          for(int j = 0;i<n;j++){
            if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 0){
              grid[i][j] = 1;
            }
          }
        }
        for(int i = 0;i<m;i++){
          for(int j = 0;j<n;j++){
            if(grid[i][j] == 0 && !visited[i][j]){
              count++;
              dfs(i,j,grid);
            }
          }
        }
        return count;
    }
};