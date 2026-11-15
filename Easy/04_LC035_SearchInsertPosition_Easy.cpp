/**
 * Problem: LeetCode 35 - Search Insert Position
 * S.No: 04
 * Difficulty: Easy
 * Unit: II (Arrays, Binary Search)
 * 
 * Approach:
 * - We are given a sorted array of distinct integers and a target value.
 * - We must find the index of the target if found. If not, return the index
 *   where it would be inserted in order.
 * - Standard Binary Search:
 *     1. Maintain two pointers: left = 0, right = n - 1.
 *     2. In each iteration, compute mid = left + (right - left) / 2.
 *     3. If nums[mid] == target, return mid.
 *     4. If nums[mid] < target, target must be in the right half -> left = mid + 1.
 *     5. If nums[mid] > target, target must be in the left half -> right = mid - 1.
 *     6. When the loop ends (left > right), 'left' will point to the exact insert position.
 * 
 * Time Complexity: O(log n) - Search space is halved in every iteration.
 * Space Complexity: O(1) - Constant extra space.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Calculate mid safely to avoid integer overflow
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }
        
        // When not found, left represents the correct insertion index
        return left;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<int> nums = {1, 3, 5, 6};
    
    // Target 5 is at index 2
    cout << "Test 1 (Target 5): " << sol.searchInsert(nums, 5) << " (Expected: 2)" << endl;
    
    // Target 2 should be inserted at index 1
    cout << "Test 2 (Target 2): " << sol.searchInsert(nums, 2) << " (Expected: 1)" << endl;
    
    // Target 7 should be inserted at index 4
    cout << "Test 3 (Target 7): " << sol.searchInsert(nums, 7) << " (Expected: 4)" << endl;
    
    return 0;
}
