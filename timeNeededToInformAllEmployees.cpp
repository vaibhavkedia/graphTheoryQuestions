#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>timeOfCompletion;
    void dfs(int node,vector<int>& informTime,vector<vector<int>>& tree){
        int maxTime = 0;
        
        timeOfCompletion[node] += informTime[node];
        for(int child:tree[node]){
            dfs(child,informTime,tree);
            maxTime = max(maxTime,timeOfCompletion[child]);
        }
        timeOfCompletion[node] += maxTime;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       vector<vector<int>>tree(n);
        timeOfCompletion = vector<int>(n);
       for(int i=0;i<manager.size();++i){
           if(manager[i] != -1){
               tree[manager[i]].push_back(i);
           }
       }
        dfs(headID,informTime,tree);
        return timeOfCompletion[headID];
    }
};