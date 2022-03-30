#include<bits/stdc++.h>
using namespace std;

class Solution {
  int dx[4] = {0,1,0,-1};
  int dy[4] = {1,0,-1,0};
  queue<pair<int,int>>q;

  void change(int x,int y,vector<vector<int>>& grid){
    int n = grid.size();
    q.push({x,y});
    grid[x][y] = 2;
    for(int i=0;i<4;++i){
      int newx = x + dx[i];
      int newy = y + dy[i];
      if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy] == 1){
        change(newx,newy,grid);
      }
    }
  }
public:
    int shortestBridge(vector<vector<int>>& grid) {
      int n = grid.size();
      int ans = INT_MAX;
      vector<vector<int>>distance(n,vector<int>(n));
      for(int i = 0;i<n;++i){
        bool isVisitedIsland = false;
        for(int j = 0;j<n;++j){
          if(grid[i][j] == 1) {
            change(i,j,grid);
            isVisitedIsland = true;
              break;
         }
        }
           if(isVisitedIsland) break;
      }

      for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
          if(grid[i][j] != 2) distance[i][j] = INT_MAX;
        }
      }

      while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(grid[x][y] == 1) ans = min(ans,distance[x][y]-1);
        q.pop();
        for(int i = 0;i<4;++i){
          int newx = x + dx[i];
          int newy = y + dy[i];
          if(newx>=0 && newy>=0 && newx<n && newy<n && distance[newx][newy] > distance[x][y] + 1){
            distance[newx][newy] = distance[x][y] + 1;
            q.push({newx,newy});
          }
        }
      }
      return ans; 

    }
};