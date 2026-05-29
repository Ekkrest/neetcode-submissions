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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* slowNext = slow->next;
        slow->next = NULL;

        ListNode* secondHalf = reverse(slowNext);

        conbine(curr, secondHalf);
    } 

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;  
        }

        return prev;
    }

    void conbine(ListNode* list1, ListNode* list2){
        while(list1 != NULL && list2 != NULL){
            ListNode* nxt1 = list1->next;
            ListNode* nxt2 = list2->next;
            list1->next = list2;
            if (nxt1 == NULL) break;
            list2->next = nxt1;

            list1 = nxt1;
            list2 = nxt2;
        }
    }
};
