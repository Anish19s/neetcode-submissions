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
       ListNode* newh=new ListNode(-1);
       newh->next=NULL;
       ListNode* pred=newh;
       ListNode* temp1=l1,*temp2=l2;
        int sum=0,carry=0;
       while(temp1 && temp2){
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp1=temp1->next;
            temp2=temp2->next;
            pred=pred->next;
       }
       while(temp1){
            sum=temp1->val+carry;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp1=temp1->next;
            pred=pred->next;
       }
        while(temp2){
            sum=temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            pred->next=new ListNode(sum);
            temp2=temp2->next;
            pred=pred->next;
       }
        if(!temp1 && !temp2 && carry!=0){
             pred->next=new ListNode(carry);
        }
        pred=newh->next;
        delete(newh);
        return pred;
    }
};
