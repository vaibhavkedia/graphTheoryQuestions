#include<bits/stdc++.h>
using namespace std;

class Solution {
   struct Node{
       int value;
       int length;
       int previousColor;
       Node(int value,int length,int previousColor){
           this->value = value;
           this->length = length;
           this->previousColor = previousColor;
       }
   };
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans(n,-1);
        vector<vector<bool>>isVisited(n,vector<bool>(2));
        vector<vector<pair<int,int>>>graph(n);
        queue<Node>q;
        
        for(const vector<int>&edges:redEdges){
            int u = edges[0];
            int v = edges[1];
            graph[u].push_back({v,0});
        }
        
        for(const vector<int>& edges:blueEdges){
            int u = edges[0];
            int v = edges[1];
            graph[u].push_back({v,1});
        }
        
        q.push(Node(0,0,-1));
        isVisited[0][0] = true;
        isVisited[0][1] = true;
        
        while(!q.empty()){
            int value = q.front().value;
            int length = q.front().length;
            int previousColor = q.front().previousColor;
            q.pop();
            if(ans[value] == -1) ans[value] = length;
            for(const pair<int,int>& childNode : graph[value]){
                int child = childNode.first;
                int color = childNode.second;
                if(color != previousColor && !isVisited[child][color]){
                    isVisited[child][color] = true;
                    q.push(Node(child,length+1,color));
                }
            }
        }
        return ans;
    }
};