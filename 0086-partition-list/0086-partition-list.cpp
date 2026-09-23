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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesshead=new ListNode(0);
        ListNode* greathead=new ListNode(0);
        ListNode* less=lesshead;
        ListNode* great=greathead;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                less->next=curr;
                less=less->next;
            }
            else{
                great->next=curr;
                great=great->next;
            }
            curr=curr->next;
        }
        less->next=greathead->next;
        great->next=NULL;
        return lesshead->next;
    }
};