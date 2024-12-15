from typing import List

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