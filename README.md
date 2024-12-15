- ## Approach 1:- Inbuilt Sorting Function

    - ### Intuition:
        The problem asks to merge two sorted arrays (`nums1` and `nums2`) into a single sorted array. Since `nums1` has extra space to accommodate all elements from `nums2`, we can copy the elements of `nums2` into `nums1` and then sort the merged array.

    - ### Approach:
        1. **Copy Elements**: First, we copy all elements from `nums2` into the vacant positions of `nums1` (i.e., positions from index `m` to `m + n - 1`).
        2. **Sort the Array**: After merging both arrays into `nums1`, we use the `sort()` function to sort `nums1` in non-decreasing order.

    - ### Steps:
        1. Iterate through `nums2` and copy each element into the corresponding position in `nums1`.
        2. Sort the entire `nums1` array using `sort()` to ensure all elements are in non-decreasing order.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
                    # Step 1: Copy the elements from nums2 into the empty spaces in nums1
                    for index in range(n):
                        nums1[m + index] = nums2[index]
                    
                    # Step 2: Sort the merged array in non-decreasing order
                    nums1.sort()
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **Copying elements**: $O(n)$, where $n$ is the length of `nums2`. We loop through `nums2` and copy each element to `nums1`.
        - **Sorting**: $O((m + n) log(m + n))$, where $m+n$ is the total number of elements in `nums1` after merging. The sorting step takes $O((m + n) log(m + n))$ time.

        Thus, the total time complexity is **$O((m + n) log(m + n))$**.

    - ### Space Complexity:
        - **In-place merging**: We are merging elements directly into `nums1` without using any extra data structures, so the space complexity is **$O(1)$** additional space.
        - **Sorting space**: The `sort()` function may use $O(log(m + n))$ space for recursion (depending on the implementation of `sort()`), but this is usually considered as part of the sorting process, so the space complexity remains **$O(1)$** for the extra space used.

        Thus, the space complexity is **$O(1)$**.