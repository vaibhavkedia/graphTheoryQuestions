#include<bits/stdc++.h>
using namespace std;

class Solution {
  vector<bool>safeNodes;
  vector<bool>isVisited;
  void dfs(int node,vector<vector<int>>& graph){
    bool isSafe = true;

    isVisited[node] = true;
    for(int child: graph[node]){
      if(!isVisited[child]){
        dfs(child,graph);
      }
      isSafe &= safeNodes[child];
    }
    safeNodes[node] = isSafe;
  }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        isVisited = safeNodes = vector<bool>(n);
        vector<int>ans;

        for(int i=0;i<n;++i){
          if(!isVisited[i]) dfs(i,graph);
        }

        for(int i=0;i<n;++i){
          if(safeNodes[i]) ans.push_back(i);
        }

        return ans;
    }
};