/**
 * Problem: LeetCode 1700 - Number of Students Unable to Eat Lunch
 * S.No: 09
 * Difficulty: Easy
 * Unit: IV (Queue, Simulation, FIFO)
 * 
 * Approach:
 * - Two types of sandwiches: 0 (circular) and 1 (square).
 * - Students stand in a queue. If the student at the front likes the top sandwich,
 *   they take it and leave. Otherwise, they go to the end of the queue.
 * - Key Observation:
 *     - Sandwiches are stacked in a strict order and cannot rotate.
 *     - Students, however, can cycle indefinitely until someone takes the sandwich.
 *     - Therefore, the sandwich stack only stops moving when NO remaining student
 *       in the entire queue wants the sandwich currently at the top of the stack!
 * - Simple Counting Method:
 *     1. Count how many students want sandwich 0 and how many want sandwich 1.
 *     2. Iterate through each sandwich from top to bottom:
 *        - If it is type 0 and we have a student wanting 0, decrement count0.
 *        - If it is type 1 and we have a student wanting 1, decrement count1.
 *        - If no student wants this sandwich, no further sandwiches can be eaten! Break out.
 *     3. Return the sum of remaining students (count0 + count1).
 * 
 * Time Complexity: O(n) - Single pass through students and sandwiches.
 * Space Complexity: O(1) - Only two integer counters used.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0; // Students who prefer circular sandwich (0)
        int count1 = 0; // Students who prefer square sandwich (1)
        
        // Count preferences
        for (int preference : students) {
            if (preference == 0) count0++;
            else count1++;
        }
        
        // Try serving sandwiches one by one from the stack
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 > 0) {
                    count0--; // Served to a student
                } else {
                    break;    // No student wants sandwich 0, queue is stuck
                }
            } else { // sandwich == 1
                if (count1 > 0) {
                    count1--; // Served to a student
                } else {
                    break;    // No student wants sandwich 1, queue is stuck
                }
            }
        }
        
        // Total students who could not eat
        return count0 + count1;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << "Test 1 Unable to eat: " << sol.countStudents(students1, sandwiches1) << " (Expected: 0)" << endl;
    
    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << "Test 2 Unable to eat: " << sol.countStudents(students2, sandwiches2) << " (Expected: 3)" << endl;
    
    return 0;
}
