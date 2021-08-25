/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int max_len = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int max_left = maxdepth(root->left);
        int max_right = maxdepth(root->right);
        max_len = max(max_len, max_left + max_right);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return max_len;
    }
    int maxdepth(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right)); 
    }
};
// @lc code=end

