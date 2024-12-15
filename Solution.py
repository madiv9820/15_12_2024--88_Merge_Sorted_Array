from typing import List

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