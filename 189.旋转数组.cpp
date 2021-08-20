#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == nums.size())
            return;
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int start, int right){
        while(start < right){
            swap(nums[start], nums[right]);
            start++;
            right--;
        }
    }

};
// @lc code=end

