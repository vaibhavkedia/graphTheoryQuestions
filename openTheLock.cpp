#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      int count = 0;
      unordered_set<string>str;
      unordered_set<string>isVisited;
      queue<string>q;

      for(string &s : deadends){
        str.insert(s);
      }
      q.push("0000");
      while(!q.empty()){
        int size = q.size();
        for(int j=0;j<size;++j){
          string s = q.front();
          q.pop();
          if(s.compare(target) == 0) return count;
          if(str.find(s) != str.end() || isVisited.find(s) != isVisited.end()) continue;
          isVisited.insert(s);
          for(int i=0;i<4;++i){
            if(s[i] != '9'){    // forward rotate
              s[i]++;
              q.push(s);
              s[i]--;
            }else{
              s[i] = '0';
              q.push(s);
              s[i] = '9';
            }

            if(s[i] != '0'){
              s[i]--;
              q.push(s);
              s[i]++;
            }else{
              s[i] = '9';
              q.push(s);
              s[i] = '0';
            }

          }
        }
        ++count;
      }
      return -1;
    }
};