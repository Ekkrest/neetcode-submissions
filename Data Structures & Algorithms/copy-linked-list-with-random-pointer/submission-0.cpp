/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node dummy(-101);
        Node* res = &dummy;
        Node* curr = head;
        unordered_map<Node*, Node*> umap;

        while(curr != nullptr){
            Node* temp = new Node(curr->val);
            res->next = temp;
            res = temp;

            umap[curr] = temp;
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = dummy.next;
        while(curr != nullptr){
            if(curr->random != nullptr){
                newCurr->random = umap[curr->random];
            }else{
                newCurr->random = nullptr;
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return dummy.next;
    }
};
