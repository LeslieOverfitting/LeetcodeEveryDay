#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans = merge(matrix);
        return ans[k - 1];
    }

    vector<int> merge(vector<vector<int>>& matrix){
        if(matrix.size() == 0)
            return {};
        if(matrix.size() == 1)
            return matrix[0];
        int index = matrix.size() / 2;
        vector<vector<int>> left;
        for(int i = 0; i < index; i++){
            left.push_back(matrix[i]);
        }
        vector<vector<int>> right;
        for(int i = index; i < matrix.size(); i++){
            right.push_back(matrix[i]);
        }
        vector<int> left_ans = merge(left);
        vector<int> right_ans = merge(right);
        vector<int> ans(left_ans.size() + right_ans.size(), 0);
        int left_index = 0;
        int right_index = 0;
        int ans_index = 0;
        while(left_index < left_ans.size() && right_index < right_ans.size()){
            if(left_ans[left_index] < right_ans[right_index]){
                ans[ans_index] = left_ans[left_index];
                left_index++;
                ans_index++;
            }else{
                ans[ans_index] = right_ans[right_index];
                right_index++;
                ans_index++;
            }
        }

        while(left_index < left_ans.size()){
            ans[ans_index] = left_ans[left_index];
            left_index++;
            ans_index++;
        }
        while(right_index < right_ans.size()){
            ans[ans_index] = right_ans[right_index];
            right_index++;
            ans_index++;
        }

        return ans;
        
    }
};
// @lc code=end

