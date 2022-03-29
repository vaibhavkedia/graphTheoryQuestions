#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();
      int dx[4] = {1,0,-1,0};
      int dy[4] = {0,1,0,-1};
      queue<pair<int,int>>q;
      vector<vector<int>>state(m,vector<int>(n));
       vector<vector<int>>ans;

      for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
          q.push({i,j});
          if(i == 0 || j == 0) state[i][j] += 1;
          else if(i == m-1 || j == n-1) state[i][j] += 2;
        }
      }
      while(!q.empty()){
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        for(int i = 0;i<4;++i){
          int x = f + dx[i];
          int y = s + dy[i];
          if(x>=0 && y>=0 && x<m && y<n && state[x][y] != state[f][s] && state[x][y] != 3 && heights[x][y] >= heights[f][s] ){
            state[x][y] = min(3,state[x][y]+state[f][s]);
            q.push({x,y});
          } 
        }
      }
      for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
          if(state[i][j] == 3){
            ans.push_back({i,j});
          }
        }
      }
      return ans;
    }
};