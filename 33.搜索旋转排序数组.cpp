/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[0]){
                // in left
                if(nums[mid] < target){
                    left = mid + 1;
                }else{
                    if(target >= nums[0]){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }else{
                if(nums[mid] > target){
                    right = mid - 1;
                }else{
                    if(target >= nums[0]){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

