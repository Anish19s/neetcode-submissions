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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c1=0;
        ListNode* temp=head;
        while(temp!=NULL){
            c1++;
            temp=temp->next;
        }
        temp=head;
        int i=0,m=c1-n;
        ListNode* pred=NULL;
        while(i<=m-1){
            pred=temp;
            temp=temp->next;
            i++;
        }
        if(temp==head){
             ListNode* pred2=head->next;
             delete(head);
             return pred2;
        }
       pred->next=temp->next;
        delete(temp);
        return head;
    }
};
