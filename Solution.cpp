#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Initialize pointers for nums1, nums2, and the index for merging into nums1
        int ptr1 = m - 1, ptr2 = n - 1, index = m + n - 1;

        // Step 2: Merge the two arrays (nums1 and nums2) into nums1
        // We compare elements from both arrays and place the larger one at the correct index in nums1
        while (ptr1 >= 0 && ptr2 >= 0)
            if (nums1[ptr1] >= nums2[ptr2]) nums1[index--] = nums1[ptr1--];  // Place element from nums1 into nums1 at the correct position
            else nums1[index--] = nums2[ptr2--];  // Place element from nums2 into nums1 at the correct position

        // Step 3: If there are remaining elements in nums1, copy them into nums1
        // No need to move elements in nums1 because they are already in the correct place
        while (ptr1 >= 0) nums1[index--] = nums1[ptr1--];  // Copy the remaining elements of nums1 into the correct position

        // Step 4: If there are remaining elements in nums2, copy them into nums1
        // This step is necessary because nums2 might still have elements left if nums1 is exhausted first
        while (ptr2 >= 0) nums1[index--] = nums2[ptr2--];  // Copy the remaining elements of nums2 into the correct position in nums1
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