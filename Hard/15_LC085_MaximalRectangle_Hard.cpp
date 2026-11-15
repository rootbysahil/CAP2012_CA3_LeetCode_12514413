/**
 * Problem: LeetCode 85 - Maximal Rectangle
 * S.No: 15
 * Difficulty: Hard
 * Unit: IV (Stack, Histogram, 2D Arrays)
 * 
 * Approach:
 * - We are given a 2D binary matrix filled with '0's and '1's.
 * - We need to find the largest rectangle containing only '1's and return its area.
 * - Histogram Reduction with Monotonic Stack:
 *     1. We can reduce this 2D problem into a series of 1D "Largest Rectangle in Histogram" problems!
 *     2. Maintain a 'heights' array of size 'cols', initialized to 0.
 *     3. Iterate row by row:
 *        - For each column j:
 *          If matrix[i][j] == '1', increment heights[j] by 1 (building taller histogram).
 *          If matrix[i][j] == '0', reset heights[j] = 0 (the vertical strip of 1s is broken).
 *     4. For each row's 'heights' array, compute the maximum rectangular area using a stack:
 *        - The stack keeps indices of heights in increasing order.
 *        - When a smaller height is encountered, pop from stack and calculate area:
 *          height = heights[popped_index]
 *          width = stack is empty ? current_index : (current_index - stack.top() - 1)
 *          area = height * width
 *     5. Update 'maxArea' across all rows.
 * 
 * Time Complexity: O(rows * cols) - Each cell is processed O(1) times.
 * Space Complexity: O(cols) - To store the histogram heights and stack for one row.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to find largest rectangle in a 1D histogram (LC 84)
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stores indices
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Use 0 as virtual height at the end (i == n) to flush out all remaining bars in stack
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;
        
        // Process each row
        for (int i = 0; i < rows; i++) {
            // Update histogram heights for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; // Reset height if broken by '0'
                }
            }
            
            // Calculate max area for this row's histogram
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }
        
        return maxRectangle;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << " (Expected: 6)" << endl;
    return 0;
}
