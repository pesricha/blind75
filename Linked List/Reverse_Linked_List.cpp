#include<iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr = head;
        if(!curr) return head;
        ListNode* post = curr->next;
        ListNode* prev = nullptr;
        while (curr)
        {
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;   
        }

        return prev;
    }
};