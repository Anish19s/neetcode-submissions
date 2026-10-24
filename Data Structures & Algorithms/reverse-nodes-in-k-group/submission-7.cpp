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
        ListNode* temp1=head;
        int c1=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            c1++;
        } 
        if(c1<k){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* prev2=NULL;
        int i=0;
        while(temp!=NULL && i<k){
            prev2=temp;
            temp=temp->next;
            prev2->next=prev;
            prev=prev2;
            i++;
        }
        head->next=reverseKGroup(temp,k);
        return prev;

    }
};
