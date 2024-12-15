from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # Step 1: Copy the elements from nums2 into the empty spaces in nums1
        for index in range(n):
            nums1[m + index] = nums2[index]
        
        # Step 2: Sort the merged array in non-decreasing order
        nums1.sort()