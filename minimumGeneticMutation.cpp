#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      int count = 0;
      queue<string>q;
      unordered_set<string>str;
      unordered_set<string>isVisited;

      for(string &s : bank){
        str.insert(s);
      }
      q.push(start);
      isVisited.insert(start);
      while(!q.empty()){
        int size = q.size();
        for(int j=0;j<size;++j){
          string s = q.front();
          q.pop();
          if(s.compare(end) == 0) return count;
          for(int i=0;i<8;++i){
            char temp = s[i];
            s[i] = 'A';
            if(str.find(s) != str.end() && isVisited.find(s) == isVisited.end()){
              q.push(s);
              isVisited.insert(s);
            }
            s[i] = 'C';
            if(str.find(s) != str.end() && isVisited.find(s) == isVisited.end()){
              q.push(s);
              isVisited.insert(s);
            }
            s[i] = 'G';
            if(str.find(s) != str.end() && isVisited.find(s) == isVisited.end()){
              q.push(s);
              isVisited.insert(s);
            }
            s[i] = 'T';
            if(str.find(s) != str.end() && isVisited.find(s) == isVisited.end()){
              q.push(s);
              isVisited.insert(s);
            }
            s[i] = temp;
          }
        }
        ++count;
      }
      return -1;
    }
};