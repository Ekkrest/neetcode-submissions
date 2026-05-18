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
        ListNode* pointer1 = list1;
        ListNode* pointer2 = list2;
        ListNode dummy(-101); // 建立在 Stack
        ListNode* ans = &dummy;

        while(pointer1 != nullptr && pointer2 != nullptr){
            if(pointer1->val < pointer2->val){
                ans->next = pointer1;
                pointer1 = pointer1->next;
            }else{
                ans->next = pointer2;
                pointer2 = pointer2->next;
            }
            ans = ans->next;
        }
        if(pointer1 != nullptr) ans->next = pointer1;
        if(pointer2 != nullptr) ans->next = pointer2;

        return dummy.next;

    }
};
