#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int  j = nums.size() - 2;
        while( j >=0 && nums[j] >= nums[j + 1]){
            j--;
        }
        if(j >= 0){
            int i = nums.size() - 1;
            while(i >= j && nums[i] <= nums[j]){
                i--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + j + 1, nums.end());
    }
};
// @lc code=end

