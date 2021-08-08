#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        m[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(m.count(sum - k) > 0 )
                ans += m[sum - k];
            m[sum] += 1;
        }
        return ans;
    }
};
// @lc code=end

