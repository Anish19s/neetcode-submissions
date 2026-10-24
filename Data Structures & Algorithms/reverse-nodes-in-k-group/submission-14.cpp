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
        ListNode* temp=head;
        int c1=0,i=0;
        while(temp){
            temp=temp->next;
            c1++;
        }
        if(c1<k){
            return head;
        }  
        temp=head;
        ListNode *prev=NULL,*nex=NULL;
        while(temp && i<k){
            nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
            i++;
        }        
        head->next=reverseKGroup(temp,k);
        return prev;
        
    }
};
