#include<bits/stdc++.h>
using namespace std;

class Solution {
  vector<vector<int>>ans;
  int n;
  void dfs(int node,vector<vector<int>>&graph,vector<bool>&isVisited,vector<int>&path){
    if(node == n-1){
      path.push_back(node);
      ans.push_back(path);
      path.pop_back();
      return;
    }
    isVisited[node] = true;
    path.push_back(node);
    for(int child: graph[node]){
      if(!isVisited[child]){
        dfs(int child,graph,isVisited,path);
      }
    }
  }
public:
     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      n = graph.size();
      vector<bool>isVisited(n);
      vector<int>path;
      dfs(0,graph,isVisited,path);
        return ans;
    }
};