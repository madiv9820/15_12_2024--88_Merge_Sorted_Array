- ## Approach 2:- Two Pointers with Extra Memory

    - ### Intuition:
        The goal is to merge two sorted arrays, `nums1` and `nums2`, into a single sorted array. Since `nums1` has extra space to accommodate all elements from `nums2`, we can use an auxiliary array (`extra_memory`) to store the merged result and then copy it back into `nums1`. This approach helps avoid overwriting elements in `nums1` during the merge process.

    - ### Approach:
        1. **Initialization**: 
            - We initialize three pointers: `ptr1` for `nums1`, `ptr2` for `nums2`, and `index` for tracking the position in the `extra_memory` array.

        2. **Merge Arrays**:
            - We compare elements from `nums1` and `nums2` (using `ptr1` and `ptr2`), and insert the smaller element into the `extra_memory` array. The corresponding pointer (`ptr1` or `ptr2`) is then incremented.
            - If there are any remaining elements in either `nums1` or `nums2`, we copy them into `extra_memory`.

        3. **Copy Back**:
            - Once the merging is complete, we copy the merged result from `extra_memory` back into `nums1`.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
                    # Step 1: Create an auxiliary array to store the merged result
                    extra_memory = [0] * (m + n)  # This will hold the final sorted array
                    ptr1, ptr2, index = 0, 0, 0  # Initialize pointers for nums1, nums2, and extra_memory

                    # Step 2: Merge elements from nums1 and nums2 while both pointers are within their respective bounds
                    while ptr1 < m and ptr2 < n:
                        if nums1[ptr1] <= nums2[ptr2]:
                            extra_memory[index] = nums1[ptr1]  # Take element from nums1
                            ptr1 += 1  # Move pointer in nums1
                        else:
                            extra_memory[index] = nums2[ptr2]  # Take element from nums2
                            ptr2 += 1  # Move pointer in nums2
                        
                        index += 1 

                    # Step 3: If there are remaining elements in nums1, copy them into extra_memory
                    while ptr1 < m:
                        extra_memory[index] = nums1[ptr1]
                        ptr1 += 1  # Move pointer in nums1
                        index += 1
                    
                    # Step 4: If there are remaining elements in nums2, copy them into extra_memory
                    while ptr2 < n:
                        extra_memory[index] = nums2[ptr2]
                        ptr2 += 1  # Move pointer in nums2
                        index += 1
                        
                    # Step 5: Copy the merged result from extra_memory back into nums1
                    for index in range(m + n):
                        nums1[index] = extra_memory[index]  # Copy each element from extra_memory to nums1
            ```
        
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **Merging**: The merging process involves comparing and copying all $m + n\ $ elements from `nums1` and `nums2` into `extra_memory`, which takes **$O(m + n)$** time.
        - **Copying back**: Copying the merged elements from `extra_memory` into `nums1` also takes **$O(m + n)$** time.
    
        Thus, the overall time complexity is **$O(m + n)$**.

    - ### Space Complexity:
        - **Auxiliary Array**: We use an additional array `extra_memory` to store the merged result, which requires **$O(m + n)$** space.
        
        Therefore, the space complexity is **$O(m + n)$** due to the auxiliary array.