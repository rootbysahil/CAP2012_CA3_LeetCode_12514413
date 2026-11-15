/**
 * Problem: LeetCode 82 - Remove Duplicates from Sorted List II
 * S.No: 13
 * Difficulty: Medium
 * Unit: III (Linked Lists, Deletion, Pointer Handling)
 * 
 * Approach:
 * - Given a sorted linked list, delete all nodes that have duplicate numbers,
 *   leaving ONLY distinct numbers from the original list.
 * - (e.g., 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 becomes 1 -> 2 -> 5).
 * - Dummy Node Approach:
 *     1. The head itself might be a duplicate, so use a 'dummy' node pointing to head.
 *     2. 'prev' points to the last known verified unique node (starts at dummy).
 *     3. 'curr' starts at head.
 *     4. In a loop while curr != nullptr:
 *        - If curr has a duplicate (curr->next != nullptr && curr->val == curr->next->val):
 *          Skip ALL nodes with this duplicate value using an inner while loop.
 *          Then connect prev->next to the node right after the duplicates: prev->next = curr->next.
 *        - Otherwise, curr is unique:
 *          Advance prev: prev = prev->next.
 *        - Advance curr: curr = curr->next.
 *     5. Return dummy.next.
 * 
 * Time Complexity: O(n) - Each node is visited at most twice.
 * Space Complexity: O(1) - In-place pointer modifications.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // Check if curr is start of duplicates
            if (curr->next != nullptr && curr->val == curr->next->val) {
                // Move curr until end of duplicates
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Link prev to node after duplicates (skipping all duplicates)
                prev->next = curr->next;
            } else {
                // curr is unique, advance prev
                prev = prev->next;
            }
            curr = curr->next;
        }
        
        return dummy.next;
    }
};

// Driver code for local testing
int main() {
    // List: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    
    Solution sol;
    ListNode* res = sol.deleteDuplicates(head);
    
    cout << "Distinct List: ";
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << "(Expected: 1 2 5)" << endl;
    
    return 0;
}
