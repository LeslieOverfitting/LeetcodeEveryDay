/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1;  j < nums.size(); j++){
                int temp = nums[i] + nums[j];
                if(temp == target){
                    return {i, j};
                }
            }    
        }
        return {};
    }
};
// @lc code=end

