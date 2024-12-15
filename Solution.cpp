#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Initialize pointers for nums1, nums2, and the extra_memory array
        int ptr1 = 0, ptr2 = 0, index = 0;
        
        // Step 2: Create an auxiliary array to store the merged result
        vector<int> extra_memory(m + n, 0);  // This will hold the merged array of size m + n

        // Step 3: Merge the two arrays (nums1 and nums2) into extra_memory
        // Compare elements from both arrays and place the smaller one into extra_memory
        while (ptr1 < m && ptr2 < n)
            if (nums1[ptr1] <= nums2[ptr2])  extra_memory[index++] = nums1[ptr1++];  // Take element from nums1
            else extra_memory[index++] = nums2[ptr2++];  // Take element from nums2

        // Step 4: If there are remaining elements in nums1, copy them into extra_memory
        while (ptr1 < m) extra_memory[index++] = nums1[ptr1++];  // Copy remaining elements from nums1

        // Step 5: If there are remaining elements in nums2, copy them into extra_memory
        while (ptr2 < n) extra_memory[index++] = nums2[ptr2++];  // Copy remaining elements from nums2

        // Step 6: Copy the merged result back into nums1
        for (int index = 0; index < m + n; ++index) nums1[index] = extra_memory[index];  // Copy each element from extra_memory to nums1
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