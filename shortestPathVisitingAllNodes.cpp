#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        int length = 0;
        int finalState = (1 << n) - 1;
        vector<vector<bool>>isVisited(n,vector<bool>(finalState+1));
        queue<pair<int,int>>q;

        for(int i=0;i<n;++i){
          q.push({i,1<<i});
        }

        while(!q.empty()){
          int size = q.size();
          length++;
          for(int i=0;i<size;++i){
            int node = q.front().first;
            int visitedNodeBitState = q.front().second;
            q.pop();
            for(int child : graph[node]){
              int newVisitedNodeBitState = visitedNodeBitState | (1<<child);
              if(!isVisited[child][newVisitedNodeBitState]){
                isVisited[child][newVisitedNodeBitState] = true;
                if(newVisitedNodeBitState == finalState) return length;
                q.push({child,newVisitedNodeBitState});
              }
            }
          }
        }
        return -1;
    }
};