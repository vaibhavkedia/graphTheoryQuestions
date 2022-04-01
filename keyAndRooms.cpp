#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool>isVisited;
    int count = 0;
    void dfs(int x,vector<vector<int>>& rooms,vector<bool>&isVisited){
        int n = rooms.size();
        isVisited[x]=true;
        for(int i : rooms[x]){
          if(!isVisited[i]){
            dfs(i,rooms,isVisited);
          }
        }
        ++count;
      }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        isVisited=vector<bool>(n);
        dfs(0,rooms,isVisited);
        return (count == n);
    }
};