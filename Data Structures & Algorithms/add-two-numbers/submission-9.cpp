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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int sum=0,carry=0;
        ListNode* head=new ListNode(-1);
        head->next=NULL;
        ListNode* pred=head;
        while(temp1!=NULL && temp2!=NULL){
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp1=temp1->next;
            temp2=temp2->next;
            pred=pred->next;
        }
        while(temp1!=NULL){
            sum=carry+temp1->val;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp1=temp1->next;
            pred=pred->next;
        }
         while(temp2!=NULL){
            sum=carry+temp2->val;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp2=temp2->next;
            pred=pred->next;
        }
        if(temp1==NULL && temp2==NULL && carry !=0){
            pred->next=new ListNode(carry);
        }
        pred=head->next;
        delete(head);
        return pred;
    }
};
