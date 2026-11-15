/**
 * Problem: LeetCode 560 - Subarray Sum Equals K
 * S.No: 10
 * Difficulty: Medium
 * Unit: II (Arrays, Prefix Sum, Hash-Based Counting)
 * 
 * Approach:
 * - We need to find the total number of continuous subarrays whose sum equals 'k'.
 * - Prefix Sum + Hash Map Approach:
 *     1. Let currSum be the cumulative sum from index 0 to current index i.
 *     2. If there exists an earlier prefix sum 'prevSum' such that:
 *        currSum - prevSum = k, then the subarray between that point and i sums to 'k'!
 *     3. Rearranging gives: prevSum = currSum - k.
 *     4. We maintain an unordered_map 'prefixFreq' to store how many times each
 *        prefix sum has occurred so far.
 *     5. Base case: prefixFreq[0] = 1 (to account for subarrays that sum to k starting
 *        from index 0).
 *     6. At each element:
 *        - currSum += num;
 *        - If (currSum - k) exists in map, add its frequency to our total count.
 *        - Increment the frequency of currSum in our map: prefixFreq[currSum]++;
 * 
 * Time Complexity: O(n) - Single pass through the array with O(1) hash map operations.
 * Space Complexity: O(n) - To store prefix sums in the hash map.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixFreq;
        prefixFreq[0] = 1; // Base case: prefix sum of 0 appears once before array starts
        
        int currSum = 0;
        int totalSubarrays = 0;
        
        for (int num : nums) {
            currSum += num; // Update running cumulative sum
            
            // Check if (currSum - k) has been seen before
            int neededSum = currSum - k;
            if (prefixFreq.find(neededSum) != prefixFreq.end()) {
                totalSubarrays += prefixFreq[neededSum];
            }
            
            // Record current prefix sum into hash map
            prefixFreq[currSum]++;
        }
        
        return totalSubarrays;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 1};
    cout << "Test 1 [1, 1, 1], k = 2: " << sol.subarraySum(nums1, 2) << " (Expected: 2)" << endl;
    
    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2 [1, 2, 3], k = 3: " << sol.subarraySum(nums2, 3) << " (Expected: 2)" << endl;
    
    return 0;
}
