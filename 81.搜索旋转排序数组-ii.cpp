/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            while(left < right && nums[left] == nums[right]){
                right--;
            }
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] >= nums[0]){
                // left
                if(target > nums[mid]){
                    left = mid + 1;
                }else {
                    if(target >= nums[0]){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }else{
                // right 
                if(target < nums[mid]){
                    right = mid - 1;
                }else {
                    if(target >= nums[0]){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

