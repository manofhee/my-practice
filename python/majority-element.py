from typing import List

# https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        memo = {}
        for one in nums:
            if one in memo:
                memo[one] += 1
            else:
                memo[one] = 1

        n = len(nums)
        for elem in memo:
            if memo[elem] > int(n/2):
                return elem
        return 0
            
        
            
classes = [[1,2],[3,5],[2,2]]
extraStudents = 2
sol = Solution()
print(f"majorityElement: {sol.majorityElement([3,2,3])}")