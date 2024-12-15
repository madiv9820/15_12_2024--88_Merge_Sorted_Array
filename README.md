# 88. Merge Sorted Array (All Approaches)

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

- ## Approach 3:- Two Pointers without extra memory

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