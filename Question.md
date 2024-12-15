# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array?envType=study-plan-v2&envId=top-interview-150)

**Type:** Easy <br>
**Topics:** Array, Two Pointers, Sorting
**Companies:** Meta, Google, Amazon, Microsoft, Bloomberg, Hubspot, Squarespace, Accenture, Infosys, Apple, Oracle, Nvidia, Yandex, Swiggy, Canonical, Adobe, Uber, Yahoo, tcs, TikTok, IBM, Zoho, PayPal, LinkedIn, EPAM Systems
<hr>

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be *stored inside the array* `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.
<hr>

### Examples:

- **Example 1:** <br>
**Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 <br>
**Output:** [1,2,2,3,5,6] <br>
**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6]. <br>
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

- **Example 2:** <br>
**Input:** nums1 = [1], m = 1, nums2 = [], n = 0 <br>
**Output:** [1] <br>
**Explanation:** The arrays we are merging are [1] and []. <br>
The result of the merge is [1].

- **Example 3:** <br>
**Input:** nums1 = [0], m = 0, nums2 = [1], n = 1 <br>
**Output:** [1] <br>
**Explanation:** The arrays we are merging are [] and [1]. <br>
The result of the merge is [1]. <br>
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
<hr>

### Constraints:
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- <code>-10<sup>9</sup> <= nums1[i], nums2[j] <= 10<sup>9</sup></code>

**Follow up:** Can you come up with an algorithm that runs in `O(m + n)` time?

### Hints
- You can easily solve this problem if you simply think about two elements at a time rather than two arrays. We know that each of the individual arrays is sorted. What we don't know is how they will intertwine. Can we take a local decision and arrive at an optimal solution?
- If you simply consider one element each at a time from the two arrays and make a decision and proceed accordingly, you will arrive at the optimal solution.