#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
      int n = arr.size();
      vector<bool>isVisited(n);
      queue<int>q;

      q.push(start);
      isVisited[start] = true;
      while(!q.empty()){
        int x = q.front();
        q.pop();
        if(arr[x] == 0) return true;
        if(x+arr[x] < n && !isVisited[x+arr[x]]){
          q.push(x+arr[x]);
          isVisited[x+arr[x]] = true;
        }
        if(x-arr[x] >= 0 && !isVisited[x-arr[x]]){
          q.push(x-arr[x]);
          isVisited[x-arr[x]] = true;
        }
      }
      return false;
    }
};