/**
 * Problem: LeetCode 24 - Swap Nodes in Pairs
 * S.No: 12
 * Difficulty: Medium
 * Unit: III (Linked Lists, Pointer Manipulation)
 * 
 * Approach:
 * - We need to swap every two adjacent nodes of a singly-linked list.
 * - Crucially, we must swap the actual nodes, not just the values inside them!
 * - Beginner-Friendly Dummy Node Approach:
 *     1. Create a 'dummy' node whose 'next' points to 'head'. This simplifies
 *        edge cases like swapping the very first two nodes.
 *     2. Maintain a pointer 'prev' initially pointing to 'dummy'.
 *     3. While prev->next != nullptr && prev->next->next != nullptr:
 *        - Let first = prev->next
 *        - Let second = prev->next->next
 *        - Re-wire the 3 pointers:
 *            first->next = second->next;  (Link first node to remaining list)
 *            second->next = first;        (Put second node before first node)
 *            prev->next = second;         (Connect previous part to second node)
 *        - Advance prev: prev = first;
 *     4. Return dummy.next as the new head.
 * 
 * Time Complexity: O(n) - Single pass through the list.
 * Space Complexity: O(1) - In-place pointer manipulation without extra memory.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list node (Provided by LeetCode)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node pointing to head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Loop while there are at least two nodes remaining to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform the pairwise swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev pointer forward for the next pair
            prev = first;
        }
        
        return dummy.next;
    }
};

// Driver code for local testing
int main() {
    // List: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    Solution sol;
    ListNode* swapped = sol.swapPairs(head);
    
    cout << "Swapped List: ";
    ListNode* curr = swapped;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "(Expected: 2 1 4 3)" << endl;
    
    return 0;
}
