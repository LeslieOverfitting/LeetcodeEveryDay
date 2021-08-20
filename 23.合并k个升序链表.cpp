#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        int mid = lists.size() / 2;
        vector<ListNode*> left;
        for(int i = 0; i < mid; i++){
            left.push_back(lists[i]);
        }
        vector<ListNode*> right;
        for(int i = mid; i < lists.size(); i++){
            right.push_back(lists[i]);
        }
        ListNode* mergeleft = mergeKLists(left);
        ListNode* mergeright = mergeKLists(right);
        return merge(mergeleft, mergeright);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* pivot = new ListNode();
        ListNode* cur = pivot;
        while(left != NULL && right != NULL){
            if (left->val <= right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        while(left != NULL){
            cur->next = left;
            left = left->next;
            cur = cur->next;
        }

        while(right != NULL){
            cur->next = right;
            cur = cur->next;
            right = right->next;
        }
        return pivot->next;
    }


};
// @lc code=end

