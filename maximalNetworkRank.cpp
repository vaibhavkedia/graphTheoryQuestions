#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<vector<int>>connections(n,vector<int>(n));
        vector<int>rank(n);
        
        for(auto &road : roads){
            ++rank[road[0]];
            ++rank[road[1]];
            connections[road[0]][road[1]] = 1;
            connections[road[1]][road[0]] = 1;
        }
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                ans = max(ans,rank[i]+rank[j] - connections[i][j]);
            }
        }
        
        return ans;
    }
};