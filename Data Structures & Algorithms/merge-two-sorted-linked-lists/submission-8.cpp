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
        ListNode* l1=list1,*l2=list2;
        ListNode* temp3=new ListNode(-1);
        temp3->next=NULL;
        ListNode* pred=temp3;

        while(l1 && l2){
            if(l1->val<=l2->val){
                pred->next=l1;
                l1=l1->next;
            }
            else{
                pred->next=l2;
                l2=l2->next;
            }
            pred=pred->next;
        }
        while(l1){
            pred->next=l1;
            l1=l1->next;
            pred=pred->next;
        }
        while(l2){
            pred->next=l2;
            l2=l2->next;
            pred=pred->next;
        }
        pred=temp3->next;
        delete(temp3);
        return pred;
    }
};
