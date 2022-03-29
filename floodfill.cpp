#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int m = image.size();
      int n = image[0].size();
      queue<pair<int,int>> q;

     vector<vector<bool>> visited(m,vector<bool>(n));
     int dx[4]={1,-1,0,0};
     int dy[4]={0,0,1,-1};

     q.push({sr,sc});

     while(!q.empty()){

       int f = q.front().first;
       int s = q.front().second;
       q.pop();

       for (int i = 0; i < 4; i++)
       {
         int x = f + dx[i];
         int y = s + dy[i];
         if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == image[f][s] && !visited[x][y] ){
           q.push({x,y});
           visited[x][y] = true;
         }
       }
       image[f][s] = newColor;
       
     }
     return image;
    }
};

