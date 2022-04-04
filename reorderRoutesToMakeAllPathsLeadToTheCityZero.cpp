#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>isVisited(n);
        vector<vector<int>>graph(n);
        vector<vector<int>>inverseGraph(n);
        queue<int>q;
        int ans = 0;

        for(int i=0;i<connections.size();++i){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            inverseGraph[v].push_back(u);
        }

        q.push(0);
        isVisited[0] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int child:graph[node]){
                if(!isVisited[child]){
                    isVisited[child] = true;
                    ans++;
                    q.push(child);
                }
            }
            for(int child:inverseGraph[node]){
                if(!isVisited[child]){
                    isVisited[child] = true;
                    q.push(child);
                }
            }
        }
        return ans;
    }
};