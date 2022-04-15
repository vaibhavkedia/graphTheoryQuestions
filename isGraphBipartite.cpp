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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        isVisited = vector<int>(n);
        color = vector<int>(n);
        
        for(int i=0;i<n;++i){
            if(!isVisited[i] && !isBipartite(i,graph)) return false;
        }
        
        return true;
    }
};