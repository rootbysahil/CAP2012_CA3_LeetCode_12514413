/**
 * Problem: LeetCode 876 - Middle of the Linked List
 * S.No: 05
 * Difficulty: Easy
 * Unit: III (Linked Lists, Slow and Fast Pointers)
 * 
 * Approach:
 * - We need to find the middle node of a singly linked list.
 * - If there are two middle nodes (even length list), return the second middle node.
 * - Tortoise and Hare (Slow and Fast Pointers):
 *     1. Initialize two pointers: 'slow' and 'fast', both starting at 'head'.
 *     2. In each step:
 *        - 'slow' moves 1 node forward: slow = slow->next
 *        - 'fast' moves 2 nodes forward: fast = fast->next->next
 *     3. When 'fast' reaches the end (fast == nullptr) or the last node
 *        (fast->next == nullptr), 'slow' will be exactly at the middle node!
 * 
 * Time Complexity: O(n) - Single pass through the linked list.
 * Space Complexity: O(1) - Only two pointer variables used.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Traverse until fast reaches the end of the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps
        }
        
        // slow is now pointing to the middle node
        return slow;
    }
};

// Driver code for local testing
int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    ListNode* mid = sol.middleNode(head);
    
    cout << "Middle node value: " << mid->val << " (Expected: 3)" << endl;
    return 0;
}
