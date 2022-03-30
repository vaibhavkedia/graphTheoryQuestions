#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>distance(m,vector<int>(n));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j] == 0) q.push({i,j});
                else distance[i][j] = INT_MAX;
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx>=0 && newy>=0 && newx<m && newy<n && distance[newx][newy] > 1 + distance[x][y]){
                    distance[newx][newy] = 1 + distance[x][y];
                    q.push({newx,newy});
                }
            }
    }
        return distance;
  }  
};