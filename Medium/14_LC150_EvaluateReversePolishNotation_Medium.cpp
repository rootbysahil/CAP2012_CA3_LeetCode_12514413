/**
 * Problem: LeetCode 150 - Evaluate Reverse Polish Notation
 * S.No: 14
 * Difficulty: Medium
 * Unit: IV (Stack, Expression Evaluation)
 * 
 * Approach:
 * - Reverse Polish Notation (RPN) is a postfix mathematical notation.
 * - Operands appear before operators (e.g. ["2", "1", "+", "3", "*"] -> (2 + 1) * 3 = 9).
 * - Standard Stack Algorithm:
 *     1. Maintain a stack of 64-bit integers (long long or int) for operands.
 *     2. Traverse each token:
 *        - If token is an operator ("+", "-", "*", "/"):
 *          Pop top element -> b (second operand).
 *          Pop next top element -> a (first operand).
 *          Evaluate: a operator b.
 *          Push the result back onto the stack.
 *        - If token is a number:
 *          Convert string to int using stoi() and push onto stack.
 *     3. At the end, the stack contains exactly one element: the final evaluated result!
 * 
 * Time Complexity: O(n) - Single pass through n tokens.
 * Space Complexity: O(n) - Stack can hold at most n / 2 operands.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for (const string& token : tokens) {
            // Check if token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop(); // Second operand
                long long a = st.top(); st.pop(); // First operand
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                // Token is an operand number
                st.push(stoll(token));
            }
        }
        
        return static_cast<int>(st.top());
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    // ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Test 1 [\"2\",\"1\",\"+\",\"3\",\"*\"]: " << sol.evalRPN(tokens1) << " (Expected: 9)" << endl;
    
    // ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) = 6
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Test 2 [\"4\",\"13\",\"5\",\"/\",\"+\"]: " << sol.evalRPN(tokens2) << " (Expected: 6)" << endl;
    
    return 0;
}
