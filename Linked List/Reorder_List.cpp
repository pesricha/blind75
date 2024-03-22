#include<iostream>
#include<stack>
#include<queue>

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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode* reversed = reverseList(slow->next);

        slow->next = nullptr;
        slow = head;
        
        while(slow)
        {
            ListNode* temp = slow->next;
            slow->next = reversed;
            if (!reversed) break;
            reversed = reversed->next;
            slow->next->next = temp;
            slow = temp;    
        }

    }
};