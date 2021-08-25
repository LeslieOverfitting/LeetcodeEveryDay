#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        m--;
        n--;
        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[last] = nums1[m];
                last--;
                m--;
            }else{
                nums1[last] = nums2[n];
                last--;
                n--;
            }
        }

        while(n >= 0){
            nums1[last] = nums2[n];
            n--;
            last--;
        }
    }
};
// @lc code=end

