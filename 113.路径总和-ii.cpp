/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> mem;
        pathSum2(root, targetSum, mem, ans);
        return ans;
    }

    void pathSum2(TreeNode* root, int targetSum, vector<int> &mem, vector<vector<int>> &ans) {
        if(root == NULL)
            return;
        targetSum -= root->val;
        mem.push_back(root->val);
        if(targetSum == 0 &&  root->left == NULL && root->right == NULL){   
            vector<int> temp;
            for(int i = 0; i < mem.size(); i++){
                temp.push_back(mem[i]);
            }
            ans.push_back(temp);
            mem.pop_back();
            return;
        }
        pathSum2(root->left, targetSum, mem, ans);
        pathSum2(root->right, targetSum, mem, ans);
        mem.pop_back();
        return;
    }
};
// @lc code=end

