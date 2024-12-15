- ## Approach 4:- Two Pointers from Start Without Extra Memory 

    - ### Intuition:
        We are given two sorted arrays `nums1` and `nums2`, and our goal is to merge them into a single sorted array, with the result stored in `nums1`. 

        - **The main challenge**: We need to perform the merge operation in-place without using additional space for another array.
        - **Key idea**: Instead of inserting elements from `nums2` into the correct position in `nums1` directly, we start by comparing elements from both arrays. We can take advantage of the available space at the end of `nums1` (which has $n$ extra zeros) to perform the merge in-place.

        - #### Key Insights:
            1. We need to maintain two pointers, `ptr1` and `ptr2`, which point to the current elements in `nums1` and `nums2`, respectively.
            2. We start merging by comparing the elements from both arrays. If an element from `nums1` is smaller, we leave it in place. If an element from `nums2` is smaller, we need to shift the elements of `nums1` to make room for it.
            3. The algorithm should ensure that no element is overwritten until it is properly shifted or inserted.

    - ### Approach:
        1. **Initialization**: We start by setting two pointers, `ptr1` and `ptr2`, to the beginning of the arrays `nums1` and `nums2`. We also need a variable $m$ to track the number of valid elements in `nums1`.

        2. **Merging Process**:
            - **Comparison**: Compare the current element from `nums1` and `nums2` (i.e., `nums1[ptr1]` and `nums2[ptr2]`).
            - If the element in `nums1` is smaller or equal, move the `ptr1` forward to the next valid element.
            - If the element in `nums2` is smaller, shift all elements in `nums1` from `ptr1` onwards to the right to make space for `nums2[ptr2]`. Then insert `nums2[ptr2]` at `nums1[ptr1]` and increment both pointers.

        3. **Remaining Elements**:
            - After comparing and merging the elements from both arrays, there may be remaining elements in `nums2` (if `ptr2` hasn't reached $n$). These should be copied directly into `nums1` from the current `ptr1` position.

    - ### Code Implementation
        - **Python Solution**
            ```python3 []
            class Solution:
                def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
                    ptr1, ptr2 = 0, 0  # Initialize two pointers: ptr1 for nums1, ptr2 for nums2
                    
                    # Step 2: Merge elements from nums1 and nums2 while both pointers are within bounds
                    while ptr1 < m and ptr2 < n:
                        # Compare elements from both arrays (nums1 and nums2)
                        # If the element in nums1 is less than or equal to the element in nums2, move ptr1
                        if nums1[ptr1] <= nums2[ptr2]:
                            ptr1 += 1  # Move ptr1 to the next element in nums1
                        else:
                            # If the element in nums2 is smaller, shift elements of nums1 starting from index m
                            # Shift elements from nums1 from index m-1 to ptr1 by one position to the right
                            for index in range(m, ptr1, -1):  # Shift the elements one by one to make room for nums2
                                nums1[index] = nums1[index - 1]
                            
                            # Insert the element from nums2 at the correct position in nums1
                            nums1[ptr1] = nums2[ptr2]
                            
                            # Move both pointers forward
                            ptr1 += 1; ptr2 += 1
                            
                            # Increase m since we've added one element from nums2 to nums1
                            m += 1

                    # Step 3: If there are remaining elements in nums2, copy them into nums1
                    while ptr2 < n:  # If nums2 still has elements, copy them to nums1
                        nums1[ptr1] = nums2[ptr2]  # Copy the remaining element from nums2 to nums1
                        ptr1 += 1  # Move pointer in nums1 forward
                        ptr2 += 1  # Move pointer in nums2 forward
            ```

        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - **Worst Case Time Complexity**: 
            - The `while` loop runs until we exhaust all elements in either `nums1` or `nums2`. In the worst case, we may have to process each element from both arrays once.
            - The `for` loop inside the `else` block shifts elements of `nums1` to the right, which may take **$O(m)$** time for each element in `nums2`.
            - Thus, the overall worst-case time complexity of the algorithm is **$O(m * n)$**, where $m$ is the number of elements in `nums1` and $n$ is the number of elements in `nums2`.

    - ### Space Complexity:
        - **Space Complexity**: 
            - The algorithm performs the merge in-place within `nums1`, and does not require any additional space beyond the input arrays. 
            - Thus, the space complexity is **$O(1)$** (constant space), as we are not using any extra space apart from the pointers and the variables already present in the input arrays.