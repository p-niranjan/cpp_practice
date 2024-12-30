// https://leetcode.com/problems/reverse-linked-list-ii/description/

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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int pos = 1;
        while(cur && pos < left) {
            prev = cur;
            cur = cur->next;            
            pos++;
        }

        ListNode* connection = prev;
        ListNode* tail = cur;
        ListNode* nxt = nullptr;
        while(cur && pos <= right)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            pos++;
        }
        if(connection)
            connection->next = prev;
        else
            head = prev;

        tail->next = cur;
        return head;
    }
};