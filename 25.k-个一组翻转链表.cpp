/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        ListNode* pivot = new ListNode();
        pivot->next = head;
        ListNode* fast = pivot;
        ListNode* slow = pivot;
        int cnt = 0;
        while(fast->next != NULL){
            fast = fast->next;
            cnt++;
            if(cnt == k){
                // reverse
                ListNode* temp_next = fast->next;
                fast->next = NULL;
                fast = slow->next;
                ListNode* temp = reverse(slow->next);
                //plot(temp);
                slow->next = temp;
                fast->next = temp_next;
                slow = fast;
                cnt = 0;
            }
        }
        return pivot->next;
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* begin = reverse(head->next);
        if (begin == NULL)
            return head;
        head->next->next = head;
        head->next = NULL;
        return begin;
    }

    void plot(ListNode* head){
        cout<<endl;
        while(head != NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

};
// @lc code=end

