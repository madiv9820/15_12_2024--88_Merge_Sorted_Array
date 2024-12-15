- ## Approach 4:- Two Pointers without extra memory

    - ### Intuition:
        The task is to merge two sorted arrays (`nums1` and `nums2`) into a single sorted array. Since `nums1` already has enough space to accommodate all elements of `nums2`, the idea is to merge the arrays starting from the end of `nums1`. This allows us to avoid overwriting elements in `nums1` while we perform the merge.

        By using two pointers (one for each array) starting from the last valid elements and another pointer for the end of `nums1`, we can compare and place the larger of the two elements at the end of `nums1`. We continue this process until all elements from both arrays are merged into `nums1`.

    - ### Approach:
        1. **Pointer Initialization**:
            - Start by setting three pointers: 
                - `ptr1` at the last valid element of `nums1` (i.e., $m - 1$).
                - `ptr2` at the last element of `nums2` (i.e., $n - 1$).
                - `index` at the last index of `nums1` (i.e., $m + n - 1$).
        
        2. **Merging Arrays**:
            - Compare the elements pointed to by `ptr1` and `ptr2`. Place the larger element at the current `index` in `nums1`, and move the corresponding pointer leftwards. After placing an element, decrement `index`.
            - Repeat this until one of the arrays (`nums1` or `nums2`) is exhausted.

        3. **Copy Remaining Elements**:
            - If any elements remain in `nums1` (i.e., `ptr1 >= 0`), they are already in place, so just move the `index` leftwards.
            - If any elements remain in `nums2` (i.e., `ptr2 >= 0`), copy them directly to `nums1`.

        4. **No Extra Memory**:
            - This approach does not require extra space (other than the input array `nums1`) as the merging happens in-place.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
                    # Step 1: Initialize pointers for nums1, nums2, and the index in nums1 where merged elements will be placed
                    # Start ptr1 at the last valid element in nums1, ptr2 at the last element in nums2, and index at the last position in nums1
                    ptr1, ptr2, index = m - 1, n - 1, m + n - 1

                    # Step 2: Merge elements from nums1 and nums2 while both pointers are within bounds
                    while ptr1 >= 0 and ptr2 >= 0:
                        # Compare elements from both arrays and place the larger one at the correct index in nums1
                        if nums1[ptr1] >= nums2[ptr2]:
                            nums1[index] = nums1[ptr1]  # Take element from nums1
                            ptr1 -= 1  # Move pointer in nums1 to the left
                        else:
                            nums1[index] = nums2[ptr2]  # Take element from nums2
                            ptr2 -= 1  # Move pointer in nums2 to the left
                        
                        index -= 1  # Move the index in nums1 to the left for the next insertion

                    # Step 3: If there are remaining elements in nums1, copy them into nums1 (they are already in place)
                    while ptr1 >= 0:
                        nums1[index] = nums1[ptr1]  # Copy the remaining element from nums1
                        ptr1 -= 1  # Move pointer in nums1 to the left
                        index -= 1  # Move the index to the left

                    # Step 4: If there are remaining elements in nums2, copy them into nums1
                    while ptr2 >= 0:
                        nums1[index] = nums2[ptr2]  # Copy the remaining element from nums2
                        ptr2 -= 1  # Move pointer in nums2 to the left
                        index -= 1  # Move the index to the left
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **$O(m + n)$**: 
            - We traverse each of the two arrays (`nums1` and `nums2`) exactly once. 
            - Every element from both arrays is compared and placed into `nums1`, and the copying happens in constant time.

    - ### Space Complexity:
        - **$O(1)$**: 
            - The merging is done in-place within `nums1`, so no additional space is required other than the input arrays themselves.