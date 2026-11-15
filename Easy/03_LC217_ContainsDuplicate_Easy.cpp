/**
 * Problem: LeetCode 217 - Contains Duplicate
 * S.No: 03
 * Difficulty: Easy
 * Unit: II (Arrays, Searching, Duplicate Detection)
 * 
 * Approach:
 * - We need to determine if any integer appears at least twice in an array.
 * - Beginner-Friendly Approach using Sorting:
 *     1. Sort the array in non-decreasing order: std::sort(nums.begin(), nums.end()).
 *     2. After sorting, identical numbers will be placed right next to each other.
 *     3. Iterate through the array from index 1 to n - 1. If nums[i] == nums[i - 1],
 *        we immediately return true.
 *     4. If the loop finishes without finding any duplicate, return false.
 * 
 * Alternative (Hash Set):
 * - We can also insert elements into an unordered_set. If an element already exists,
 *   return true. (O(n) time, O(n) space).
 * 
 * Time Complexity: O(n log n) - Due to sorting the array.
 * Space Complexity: O(1) auxiliary space (or O(log n) depending on introsort implementation).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Check adjacent elements for equality
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true; // Duplicate found
            }
        }
        
        // Step 3: No duplicates found
        return false;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<int> test1 = {1, 2, 3, 1};
    cout << "Test 1 [1, 2, 3, 1]: " << (sol.containsDuplicate(test1) ? "true" : "false") << " (Expected: true)" << endl;
    
    vector<int> test2 = {1, 2, 3, 4};
    cout << "Test 2 [1, 2, 3, 4]: " << (sol.containsDuplicate(test2) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}
