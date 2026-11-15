/**
 * Problem: LeetCode 1486 - XOR Operation in an Array
 * S.No: 01
 * Difficulty: Easy
 * Unit: I (Basic Concepts, Arrays, Bitwise Operations)
 * 
 * Approach:
 * - We are given two integers 'n' (array size) and 'start'.
 * - Each element is defined as: nums[i] = start + 2 * i.
 * - We can simply iterate from i = 0 to n - 1, compute the value of nums[i],
 *   and perform bitwise XOR (^) with an accumulator variable 'ans'.
 * - Start with ans = 0 because for any integer X, X ^ 0 = X.
 * 
 * Time Complexity: O(n) - Single loop running n times.
 * Space Complexity: O(1) - Only a few integer variables used (constant space).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0; // Initialize answer to 0
        
        // Loop from index 0 to n - 1
        for (int i = 0; i < n; i++) {
            int currentNum = start + 2 * i; // Compute element according to rule
            ans = ans ^ currentNum;          // XOR with accumulator
        }
        
        return ans; // Return the final XOR result
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    // Test Case 1: n = 5, start = 0 -> nums = [0, 2, 4, 6, 8] -> XOR = 8
    cout << "Test 1 (n=5, start=0): " << sol.xorOperation(5, 0) << " (Expected: 8)" << endl;
    
    // Test Case 2: n = 4, start = 3 -> nums = [3, 5, 7, 9] -> XOR = 8
    cout << "Test 2 (n=4, start=3): " << sol.xorOperation(4, 3) << " (Expected: 8)" << endl;
    
    return 0;
}
