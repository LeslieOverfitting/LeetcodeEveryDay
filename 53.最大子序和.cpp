/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size() + 1];
        dp[0] = nums[0];
        int max_ans = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_ans = max(max_ans, dp[i]);
        }
        return max_ans;
    }
};
// @lc code=end

