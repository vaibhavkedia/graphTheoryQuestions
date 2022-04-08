#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<int>q;
        vector<int>changes = {jug1Capacity,jug2Capacity,-jug1Capacity,-jug2Capacity};
        unordered_set<int>isVisited;

        q.push(0);
        isVisited.insert(0);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current == targetCapacity) return true;
            for(int i=0;i<4;++i){
                int newCurrent = current + changes[i];
                if(newCurrent  >= 0 && newCurrent <= (jug1Capacity+jug2Capacity) && isVisited.find(newCurrent) == isVisited.end() ){
                    isVisited.insert(newCurrent);
                    q.push(newCurrent);
                }
            }
        }
        return false;
    }
};