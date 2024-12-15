#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Copy elements from nums2 into the empty slots in nums1
        for(int index = 0; index < n; ++index) {
            nums1[m + index] = nums2[index];  // Place each element of nums2 into the empty spaces of nums1
        }

        // Step 2: Sort the merged array
        sort(nums1.begin(), nums1.end());  // Sort the entire nums1 array in non-decreasing order
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