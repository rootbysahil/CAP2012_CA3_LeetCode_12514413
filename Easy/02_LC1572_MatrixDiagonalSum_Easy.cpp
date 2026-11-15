/**
 * Problem: LeetCode 1572 - Matrix Diagonal Sum
 * S.No: 02
 * Difficulty: Easy
 * Unit: II (2D Arrays, Diagonal Traversal)
 * 
 * Approach:
 * - We are given an n x n square matrix.
 * - Primary diagonal elements are at indices [i][i].
 * - Secondary diagonal elements are at indices [i][n - 1 - i].
 * - In a single loop from i = 0 to n - 1:
 *     1. Add the primary diagonal element: mat[i][i].
 *     2. Add the secondary diagonal element: mat[i][n - 1 - i].
 *     3. If n is odd, the exact center element mat[i][i] where i == n - 1 - i
 *        would be counted twice, so we only add it once when i != n - 1 - i.
 * 
 * Time Complexity: O(n) - We traverse through n rows once.
 * Space Complexity: O(1) - No extra data structure is used.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            // Add primary diagonal element
            totalSum += mat[i][i];
            
            // Add secondary diagonal element only if it's not the same center element
            int secondaryCol = n - 1 - i;
            if (i != secondaryCol) {
                totalSum += mat[i][secondaryCol];
            }
        }
        
        return totalSum;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    // Test Case: 3x3 matrix
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // Primary diagonal: 1, 5, 9
    // Secondary diagonal: 3, 5 (center skipped), 7
    // Total sum = 1 + 5 + 9 + 3 + 7 = 25
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Test 1 Diagonal Sum: " << sol.diagonalSum(mat) << " (Expected: 25)" << endl;
    return 0;
}
