#include<iostream>>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort 
        for(int i = 0; i < intervals.size(); i++){
            for(int j = 1; j < intervals.size() - i; j++){
                if(intervals[j][0] < intervals[j - 1][0]){
                    swap(intervals[j], intervals[j - 1]);
                }
            }
        }
        vector<vector<int>> ans;
        int j = 0;
        while(j < intervals.size()){
            vector<int> temp;
            int start = intervals[j][0];
            int end = intervals[j][1];
            int i = j + 1;
            while(i < intervals.size()){
                if(intervals[i][0] <= end){
                    end = max(end, intervals[i][1]);
                    i++;
                }else{
                    break;
                }
            }
            j = i;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

