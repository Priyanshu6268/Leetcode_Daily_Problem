//    https://leetcode.com/problems/delete-node-in-a-linked-list/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; //copying the next node value
        node->next = node->next->next; // deleting the next node
    }
};
