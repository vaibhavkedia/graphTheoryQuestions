#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      int n = grid.size();
      int dx[4] = {1,0,-1,0};
      int dy[4] = {0,1,0,-1};
      int ans = 0;
      queue<pair<int,int>>q;
      vector<vector<int>>distance(n,vector<int>(n)); //distance[i][j] is the distance of (i,j) from land(1).

      for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
          if(grid[i][j] == 1) q.push({i,j});
          else distance[i][j] = INT_MAX;
        }
      }
      while(!q.empty()){
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        ans = max(ans,distance[f][s]);
        for(int i = 0;i<4;i++){
          int x = f + dx[i];
          int y = s +dy[i];
          if(x>=0 && y>=0 && x<n && y<n && distance[x][y] > 1 + distance[f][s]){
            distance[x][y] = 1 + distance[f][s];
            q.push({x,y});
          }
        }
      }
      if(ans == 0) return -1;
      return ans;
      
    }
};