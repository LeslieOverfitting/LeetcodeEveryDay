/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int count = 0;
        while(ans > 0){
           count += ans % 2;
           ans /= 2;
        }
        return count;
    }
};
// @lc code=end

