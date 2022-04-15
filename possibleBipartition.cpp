#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>isVisited;
    vector<int>color;
    
    bool isBipartite(int node,vector<vector<int>>&graph){
        isVisited[node] = 1;
        
        for(int child:graph[node]){
            if(!isVisited[child]){
                color[child] = !color[node];
                if(!isBipartite(child,graph)) return false;
            }
            else if(color[node] == color[child]) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(N+1);
        isVisited = vector<int>(N+1);
        color = vector<int>(N+1);
        
        for(int i=0;i<dislikes.size();++i){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=1;i<=N;++i){
            if(!isVisited[i] && !isBipartite(i,graph)) return false;
        }
        
        return true;
    }
};