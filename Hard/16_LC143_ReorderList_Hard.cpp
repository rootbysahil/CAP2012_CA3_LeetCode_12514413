/**
 * Problem: LeetCode 143 - Reorder List
 * S.No: 16
 * Difficulty: Hard (Assigned under Hard in CA3 table)
 * Unit: III (Linked Lists, Reversal, Merging, Pointers)
 * 
 * Approach:
 * - We are given a list: L0 -> L1 -> L2 -> ... -> Ln - 1 -> Ln
 * - We must reorder it to: L0 -> Ln -> L1 -> Ln - 1 -> L2 -> Ln - 2 -> ...
 * - This problem is solved in 3 clean, beginner-friendly steps:
 * 
 *   Step 1: Find the Middle Node (Slow and Fast Pointers)
 *           'slow' moves 1 step, 'fast' moves 2 steps.
 *           When fast reaches the end, 'slow' points to the middle of the list.
 * 
 *   Step 2: Reverse the Second Half
 *           Reverse the sublist starting from 'slow->next'.
 *           Disconnect the first half by setting slow->next = nullptr.
 * 
 *   Step 3: Merge the Two Halves Alternately
 *           Take one node from the first half, then one node from the reversed second half.
 * 
 * Time Complexity: O(n) - O(n) to find middle + O(n) to reverse + O(n) to merge.
 * Space Complexity: O(1) - All pointer operations performed in-place.
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return; // 0, 1, or 2 nodes don't need reordering
        }
        
        // --- STEP 1: Find Middle Node ---
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // --- STEP 2: Reverse Second Half ---
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // Disconnect first half from second half
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        // 'prev' is now the head of the reversed second half
        
        // --- STEP 3: Merge Two Halves Alternately ---
        ListNode* p1 = head; // First half pointer
        ListNode* p2 = prev; // Second half pointer
        
        while (p2 != nullptr) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            
            p1->next = p2;       // Link first half node to second half node
            p2->next = temp1;    // Link second half node back to next first half node
            
            p1 = temp1;          // Move p1 forward
            p2 = temp2;          // Move p2 forward
        }
    }
};

// Driver code for local testing
int main() {
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    sol.reorderList(head);
    
    // Result should be: 1 -> 5 -> 2 -> 4 -> 3
    cout << "Reordered List: ";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "(Expected: 1 5 2 4 3)" << endl;
    
    return 0;
}
