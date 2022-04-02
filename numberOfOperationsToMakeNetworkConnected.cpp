#include<bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
    vector<bool>isVisited;
    void dfs(int node,vector<vector<int>>& graph){
        isVisited[node] = true;
        for(int child : graph[node]){
            if(!isVisited[child]){
                dfs(child,graph);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        isVisited = vector<bool>(n);
        vector<vector<int>> graph(n);

        for(int i = 0;i<connections.size();++i){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i=0;i<n;++i){
            if(!isVisited[i]){
                dfs(i,graph);
                count++;
            }
        }

        if(connections.size() >= n-1) return count-1;
        return -1;
    }
};