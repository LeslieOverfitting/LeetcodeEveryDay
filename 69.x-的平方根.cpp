/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x / 2 + 1;
        while(left <= right){
            long mid = (left + right) / 2;
            long temp = mid * mid;
            if(temp < x){
                left = mid + 1;
            }else if (temp > x){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return right;
    }
};
// @lc code=end

