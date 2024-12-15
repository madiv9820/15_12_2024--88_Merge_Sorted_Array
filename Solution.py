from typing import List

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