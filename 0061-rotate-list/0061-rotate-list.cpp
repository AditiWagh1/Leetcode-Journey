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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next||k==0) return head;
        ListNode* tail=head;
        int n=1;
        while(tail->next!=nullptr)
        {
            tail=tail->next;
            n++;
        }
        k=k%n;
        tail->next=head;
        int steps_to_newtail=n-k;
        ListNode* newtail=tail;
        while(steps_to_newtail--)
        {
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        return newhead;
    }//tc=O(n) nd sc=O(1) as it is inplace
};