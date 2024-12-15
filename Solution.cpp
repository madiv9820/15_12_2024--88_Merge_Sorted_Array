#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Initialize pointers for nums1, nums2, and the index for merging into nums1
        int ptr1 = 0, ptr2 = 0;  // ptr1 points to the first element in the valid part of nums1
                                // ptr2 points to the first element in nums2
        
        // Step 2: Merge the two arrays (nums1 and nums2) into nums1
        // We compare elements from both arrays and place the larger one at the correct index in nums1
        while(ptr1 < m && ptr2 < n) {  // Loop until either nums1 or nums2 is exhausted
            // Compare the elements at ptr1 in nums1 and ptr2 in nums2
            if(nums1[ptr1] <= nums2[ptr2]) ++ptr1;  // If element in nums1 is smaller or equal, just move ptr1 forward
            else {
                // If element in nums2 is smaller, we need to insert it into nums1
                // Step 3: Shift elements in nums1 to the right to make space for nums2[ptr2]
                for(int index = m; index > ptr1; --index) 
                    nums1[index] = nums1[index - 1];  // Shift each element one position to the right

                // Now insert nums2[ptr2] into the correct position at ptr1 in nums1
                nums1[ptr1] = nums2[ptr2];
                
                // Move the pointers forward for both arrays and increase the size of nums1 (m)
                ++ptr1; ++ptr2;
                ++m;  // We have added one element from nums2 to nums1, so increase m
            }
        }

        // Step 4: If there are remaining elements in nums2, copy them into nums1
        // This step is necessary because nums2 might still have elements left if nums1 is exhausted first
        while(ptr2 < n) nums1[ptr1++] = nums2[ptr2++];  // Copy the remaining elements from nums2 into nums1
    }
};

int main() {
    vector<vector<int>> nums1 = {{1,2,3,0,0,0}, {1}, {0}};
    vector<vector<int>> nums2 = {{2,5,6}, {}, {1}};
    vector<vector<int>> output = {{1,2,2,3,5,6}, {1}, {1}};
    vector<int> m = {3,1,0}, n = {3,0,1};

    Solution sol;
    for(int index = 0; index < 3; ++index) {
        sol.merge(nums1[index], m[index], nums2[index], n[index]);
        bool match = true;

        for(int i = 0; i < nums1.size(); ++i)
            if(nums1[index][i] != output[index][i]) { match = false; break; }
        
        cout << (match ? "true": "false") << endl;
    }
}