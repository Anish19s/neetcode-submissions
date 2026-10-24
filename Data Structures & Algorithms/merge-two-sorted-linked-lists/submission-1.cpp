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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp3=new ListNode(-1);
        temp3->next=NULL;
        ListNode* pred=temp3;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                pred->next=temp1;
                temp1=temp1->next;
            }
            else{
                pred->next=temp2;
                temp2=temp2->next;
            }
            pred=pred->next;
        }
         while(temp1!=NULL){
                pred->next=temp1;
                temp1=temp1->next;
                 pred=pred->next;
        }
         while(temp2!=NULL){
                pred->next=temp2;
                temp2=temp2->next;
                 pred=pred->next;
        }
        pred=temp3->next;
        delete(temp3);
        return pred;
    }
};
