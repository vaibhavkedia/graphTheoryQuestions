#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>inDegree(n);
        
        int size = edges.size();
        
        for(int i=0;i<size;++i){
            inDegree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;++i){
            if(inDegree[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};