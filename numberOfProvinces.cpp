#include<bits/stdc++.h>
using namespace std;

class Solution {
  int count = 0;
  vector<bool>isVisited;
  void dfs(int node,vector<vector<int>>&isConnected){
    isVisited[node] = true;
    for(int i = 0;i<isConnected[node].size();++i){
      if(isConnected[node][i] == 1 && !isVisited[i]){
        dfs(i,isConnected);
      }
    }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        isVisited = vector<bool>(n);

        for(int i = 0;i<n;++i){
          if(!isVisited[i]){
            ++count;
            dfs(i,isConnected);
          }
        }

        return count;
        
    }
};