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
    ListNode* rev(ListNode* head){
        ListNode* curr=head,*prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(n==1){
        ListNode* curr=head,*prev=NULL;
        if(!curr->next){
             delete(curr);
             return NULL;
        }
        while(curr && curr->next){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete(curr);
        return head;
       }
       ListNode* temp3=rev(head);
       ListNode* temp=temp3;

       
       int i=1;
       ListNode* pred=NULL;
       while(temp && i<n){
            pred=temp;
            temp=temp->next;
            i++;
       }
       pred->next=temp->next;
       delete(temp);
        ListNode* temp6=rev(temp3);
        return temp6;
    }
};
