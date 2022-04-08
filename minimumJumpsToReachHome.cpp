#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x){
      int jumps = 0;
      vector<vector<bool>>isVisited(40001,vector<bool>(2));
      queue<pair<int,int>>q;

      for(int child : forbidden){
        isVisited[child][0] = true;
        isVisited[child][1] = true;
      }

      q.push({0,-1});
      isVisited[0][0] = true;
      isVisited[0][1] = true;

      while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;++i){
          int position = q.front().first;
          int direction = q.front().second;
          q.pop();

          if(position == x) return jumps;

          if(position+a <= 40000 && !isVisited[position+a][0]){
            q.push({position+a,0});
            isVisited[position+a][0] = true;
          }

          if(position-b >= 0 && !isVisited[position-b][1]){
            q.push({position-b,1});
            isVisited[position-b][1] = true;
          }
        }
        jumps++;
      }
      return -1;
    }
}; 