#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val > list2->val)
        {
            std::swap(list1,list2);
        }

        if(!list1->next)
        {
            list1->next = list2;
            return list1;
        }

        ListNode* curr = list1;
        ListNode* iter1 = list1->next;
        ListNode* iter2 = list2;

        while (iter1 && iter2)
        {
            if (iter1->val < iter2->val)
            {
                curr->next = iter1;
                curr = iter1;
                iter1 = iter1->next;
            }

            else
            {
                curr->next = iter2;
                curr = iter2;
                iter2 = iter2->next;
            }
        }

        if(iter2)
        {
            curr->next = iter2;
        }

        else
        {
            curr->next = iter1;
        }

        return list1;
    }

    ListNode* mergeKListsRecurser(std::vector<ListNode*>& lists, int start, int end)
    {
        if (start == end) return lists[start];
        if (start+1 == end) return mergeTwoLists(lists[start], lists[end]);
        
        int mid = start + (end-start)/2;

        ListNode* left = mergeKListsRecurser(lists, start,mid);
        ListNode* right = mergeKListsRecurser(lists,mid+1,end);

        return mergeTwoLists(left,right);
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        return mergeKListsRecurser(lists, 0 , lists.size() -1 );
    }
};