/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* odd = head;
        ListNode* ans = odd;
        ListNode* even = head->next;
        ListNode* mark = even;
        while(even!=NULL){
            odd->next = even->next;
            if(odd->next!=NULL)
                odd = odd->next;
            if(even->next!=NULL){
                even->next = even->next->next;
                even = even->next;
            }
            else
                break;
        }
        odd->next = mark;
        return ans;
        
        
    }
};
