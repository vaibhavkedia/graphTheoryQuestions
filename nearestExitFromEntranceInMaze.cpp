#include<bits/stdc++.h>
using namespace std;

class Solution {
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  queue<pair<int ,int>>q;
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int length = 1;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
          int size = q.size();
          for(int i = 0;i<size;++i){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j = 0;j<4;++j){
              int newx = x + dx[j];
              int newy = y + dy[j];
              if(newx >= 0 && newy >= 0 && newx < m && newy < n && maze[newx][newy] != '+'){
                if(newx == 0 || newy == 0 || newx == m-1 || newy == n-1) return length;
                q.push({newx,newy});
                maze[newx][newy] = '+';
              }
            }
          }
          ++length;
        }
        return -1;
    }
};