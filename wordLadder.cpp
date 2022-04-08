#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int count = 1;
      queue<string>q;
      unordered_set<string>str;
      unordered_set<string>isVisited;

      for(string &s : wordList){
        str.insert(s);
      }

      q.push(beginWord);
      isVisited.insert(beginWord);
      while(!q.empty()){
        int size = q.size();
        for(int j=0;j<size;++j){
          int s = q.front();
          q.pop();
          if(s.compare(endWord)==0) return count;
          for(int i=0;i<s.size();++i){
            int temp = s[i];
            for(char k = 'a';k<='z';++k){
              s[i] = k;
              if(str.find(s) != str.end() && isVisited.find(s) == isVisited.end()){
                q.push(s);
                isVisited.insert(s);
              }
            }
            s[i] = temp;
          }
        }
        ++count;
      }
      return 0;
    }
};