from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: ([1,2,3,0,0,0], 3, [2,5,6], 3, [1,2,2,3,5,6]),
                            2: ([1], 1, [], 0, [1]),
                            3: ([0], 0, [1], 1, [1])}
        self.__obj = Solution()
        return super().setUp()

    @timeout(0.5)
    def test_case_1(self):
        nums1, m, nums2, n, output = self.__testcases[1]
        self.__obj.merge(nums1 = nums1, m = m, nums2 = nums2, n = n)
        self.assertTrue(all(x == o for x, o in zip(nums1, output)))

    @timeout(0.5)
    def test_case_2(self):
        nums1, m, nums2, n, output = self.__testcases[2]
        self.__obj.merge(nums1 = nums1, m = m, nums2 = nums2, n = n)
        self.assertTrue(all(x == o for x, o in zip(nums1, output)))

    @timeout(0.5)
    def test_case_3(self):
        nums1, m, nums2, n, output = self.__testcases[3]
        self.__obj.merge(nums1 = nums1, m = m, nums2 = nums2, n = n)
        self.assertTrue(all(x == o for x, o in zip(nums1, output)))

if __name__ == '__main__': unittest.main()