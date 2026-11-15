/**
 * Problem: LeetCode 54 - Spiral Matrix
 * S.No: 11
 * Difficulty: Medium
 * Unit: II (2D Arrays, Matrix Traversal)
 * 
 * Approach:
 * - We need to traverse an m x n matrix in clockwise spiral order.
 * - Maintain four boundaries:
 *     - 'top' starts at row 0
 *     - 'bottom' starts at row m - 1
 *     - 'left' starts at col 0
 *     - 'right' starts at col n - 1
 * - In a loop while top <= bottom && left <= right:
 *     1. Move Right: Traverse row 'top' from 'left' to 'right', then top++.
 *     2. Move Down: Traverse col 'right' from 'top' to 'bottom', then right--.
 *     3. Move Left: If top <= bottom, traverse row 'bottom' from 'right' to 'left', then bottom--.
 *     4. Move Up: If left <= right, traverse col 'left' from 'bottom' to 'top', then left++.
 * - Repeat until boundaries cross.
 * 
 * Time Complexity: O(m * n) - Every element of the matrix is visited exactly once.
 * Space Complexity: O(1) auxiliary space (excluding the output vector of size m * n).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse from left to right along the top boundary
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++; // Shrink top boundary
            
            // 2. Traverse from top to bottom along the right boundary
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--; // Shrink right boundary
            
            // 3. Traverse from right to left along the bottom boundary (check condition)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--; // Shrink bottom boundary
            }
            
            // 4. Traverse from bottom to top along the left boundary (check condition)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++; // Shrink left boundary
            }
        }
        
        return result;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> res = sol.spiralOrder(matrix);
    cout << "Spiral Order: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << "(Expected: 1 2 3 6 9 8 7 4 5)" << endl;
    
    return 0;
}
