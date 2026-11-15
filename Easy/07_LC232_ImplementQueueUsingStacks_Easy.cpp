/**
 * Problem: LeetCode 232 - Implement Queue using Stacks
 * S.No: 07
 * Difficulty: Easy
 * Unit: IV (Stacks, Queues, FIFO Operations)
 * 
 * Approach:
 * - A Stack follows LIFO (Last-In-First-Out).
 * - A Queue follows FIFO (First-In-First-Out).
 * - We can simulate a Queue using TWO stacks:
 *     1. 'inputStack': Used for incoming elements (push).
 *     2. 'outputStack': Used for outgoing elements (pop / peek).
 * - Operations:
 *     - push(x): Always push onto 'inputStack'.
 *     - pop() / peek():
 *       If 'outputStack' is empty, pour all elements from 'inputStack' into 'outputStack'.
 *       By popping from inputStack and pushing to outputStack, the order of elements
 *       is completely reversed, transforming LIFO into FIFO!
 *       Then pop or peek from 'outputStack'.
 *     - empty(): True only if BOTH 'inputStack' and 'outputStack' are empty.
 * 
 * Time Complexity:
 *   - push(): O(1)
 *   - pop(), peek(): Amortized O(1) (Each element is moved at most once)
 *   - empty(): O(1)
 * Space Complexity: O(n) - Storing n elements across two stacks.
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;
    
    // Helper function to shift elements from inputStack to outputStack
    void shiftStacks() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    // Push element x to the back of queue
    void push(int x) {
        inputStack.push(x);
    }
    
    // Removes the element from the front of queue and returns it
    int pop() {
        shiftStacks();
        int frontVal = outputStack.top();
        outputStack.pop();
        return frontVal;
    }
    
    // Get the front element
    int peek() {
        shiftStacks();
        return outputStack.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

// Driver code for local testing
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << " (Expected: 1)" << endl;
    cout << "Pop: " << q.pop() << " (Expected: 1)" << endl;
    cout << "Empty: " << (q.empty() ? "true" : "false") << " (Expected: false)" << endl;
    return 0;
}
