/**
 * Problem: LeetCode 1047 - Remove All Adjacent Duplicates In String
 * S.No: 08
 * Difficulty: Easy
 * Unit: IV (Stack, Push/Pop, String Processing)
 * 
 * Approach:
 * - We are given a string 's'. Repeatedly remove two adjacent and equal letters
 *   until no more adjacent duplicates remain.
 * - Stack-based Approach (using std::string as a stack):
 *     1. We can maintain a result string that acts like a stack.
 *     2. For each character 'ch' in string 's':
 *        - If the result string is not empty AND its last character matches 'ch':
 *          Remove the last character using pop_back() (they cancel each other out).
 *        - Otherwise, append 'ch' using push_back().
 *     3. Using std::string directly as a stack avoids needing an extra reversal step!
 * 
 * Time Complexity: O(n) - We iterate through string of length n once; push/pop are O(1).
 * Space Complexity: O(n) - Result string stores at most n characters.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string result = ""; // acts as a stack
        
        for (char ch : s) {
            // If top of stack matches current character, remove both (pop)
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                // Otherwise push current character onto stack
                result.push_back(ch);
            }
        }
        
        return result;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    // Test 1: "abbaca" -> "ca" (bb removed -> aaca -> aa removed -> ca)
    cout << "Test 1 (\"abbaca\"): " << sol.removeDuplicates("abbaca") << " (Expected: \"ca\")" << endl;
    
    // Test 2: "azxxzy" -> "ay" (xx removed -> azzy -> zz removed -> ay)
    cout << "Test 2 (\"azxxzy\"): " << sol.removeDuplicates("azxxzy") << " (Expected: \"ay\")" << endl;
    
    return 0;
}
