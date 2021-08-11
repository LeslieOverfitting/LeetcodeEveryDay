#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int min_val = prices[0];
        int max_ret = 0;
        for(int i = 1; i < prices.size(); i++){
            min_val = min(min_val, prices[i]);
            max_ret = max(prices[i] - min_val, max_ret);
        }
        return max_ret;
    }
};
// @lc code=end

