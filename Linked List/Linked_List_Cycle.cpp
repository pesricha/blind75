#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextptr) : val(0), next(nextptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;

        while(fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            if (slowptr == fastptr)
            {
                return true;
            }
        }

        return false;
    }
};