#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<bool>>visited;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dfs (int x,int y,vector<vector<char>>& grid){
  int m = grid.size();
  int n = grid[0].size();
  visited[x][y] = true;

  for(int i = 0;i<4;i++){
    int newx = x + dx[i];
    int newy = y + dy[i];
    if(newx >=0 && newy >=0 && newx < m && newy < n && grid[newx][newy] == '1' && !visited[newx][newy])
    {
      dfs(newx,newy,grid);
    }
    }
    
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m,vector<bool>(n));
        int count = 0;
        for(int i = 0;i<m;i++){
          for(int j = 0;j<n;j++){
            if(grid[i][j] == '1' && !visited[i][j]){
              count++;
              dfs(i,j,grid);
            }
          }
        }
        return count;
    }
};
