#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> link(numCourses, vector<int>());
        vector<int> count(numCourses, 0);
        for(auto x : prerequisites){
            link[x[1]].push_back(x[0]);
            count[x[0]] += 1;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(count[i] == 0){
               q.push(i);
            }
        }
        int cnt = 0;
        while(q.size() > 0){
            int temp = q.front();
            q.pop();
            count[temp] = -1;
            cnt++;
            for(auto x: link[temp]){
                count[x]--;
                if(count[x] == 0){
                    q.push(x);
                }
            }
        }
        if(cnt == numCourses)
            return true;
        else
            return false;
    }
};
// @lc code=end

