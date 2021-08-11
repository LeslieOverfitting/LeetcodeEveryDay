#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        // 0 无操作 1 第一次买入 2 第一次卖出 3 第二次买入 4 第二次卖出
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
            dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3]);
            dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4]);
        }
        return dp[prices.size() - 1][4];

    }
};
// @lc code=end

