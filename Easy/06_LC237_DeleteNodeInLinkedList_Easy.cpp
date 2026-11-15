/**
 * Problem: LeetCode 237 - Delete Node in a Linked List
 * S.No: 06
 * Difficulty: Easy
 * Unit: III (Linked Lists, Pointer Manipulation)
 * 
 * Approach:
 * - We are given only the pointer to the node that needs to be deleted.
 * - Crucially, we do NOT have access to the 'head' of the linked list.
 * - Problem guarantees the given node is NOT the last tail node.
 * - Clever Value-Copy Trick:
 *     1. We cannot change the previous node's 'next' pointer because we don't have it.
 *     2. Instead, copy the data of the NEXT node into the CURRENT node:
 *        node->val = node->next->val;
 *     3. Now bypass the next node:
 *        node->next = node->next->next;
 *     4. This effectively deletes the next node while making the current node
 *        take its identity!
 * 
 * Time Complexity: O(1) - Constant time operations.
 * Space Complexity: O(1) - No extra memory allocated.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list node (Provided by LeetCode)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value from the next node into current node
        node->val = node->next->val;
        
        // Step 2: Keep track of next node to free memory
        ListNode* temp = node->next;
        
        // Step 3: Link current node to the node after next
        node->next = node->next->next;
        
        // Step 4: Free the bypassed node's memory
        delete temp;
    }
};

// Driver code for local testing
int main() {
    // List: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    
    // Delete node with value 5
    Solution sol;
    sol.deleteNode(head->next);
    
    // Print resulting list: should be 4 -> 1 -> 9
    cout << "List after deleting node 5: ";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "(Expected: 4 1 9)" << endl;
    
    return 0;
}
