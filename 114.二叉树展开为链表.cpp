#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
       fun(root);
    }
    TreeNode* fun(TreeNode* root){
        if(root == NULL)
            return NULL;
        TreeNode* left = fun(root->left);
        TreeNode* right = fun(root->right);
        if(left != NULL){
            root->right = left;
            while(left->right != NULL){
                left = left->right;
            }
            left->right = right;
        }else{
            root->right = right;
        }
        root->left = NULL;
        return root;
    }
};
// @lc code=end

