#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[8] = {1,0,-1,0,1,-1,1,-1};
        int dy[8] = {0,1,0,-1,1,-1,-1,1};
        queue<pair<int,int>>q;
        int length = 1;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
          return -1;
        }
        
        if(n == 1) return 1;
        
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()){
          ++length;
          int size = q.size();
          for(int i = 0;i<size;++i){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<8;++i){
              int newx = x + dx[i];
              int newy = y + dy[i];
              if(newx>=0 && newy>=0 && newx<m && newy<n && grid[newx][newy]==0){
                if(newx == n-1 && newy == n-1) return length;
                q.push({newx,newy});
                 grid[newx][newy] = 1;
            }
          }
          }
          
        }
        return -1;
    }
};