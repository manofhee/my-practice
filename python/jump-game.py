from typing import List

# https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def check(self, index):
        if index == self.last_index:
            return True
        
        if index in self.memo:
            return self.memo[index]

        for i in range(1, self.nums[index]+1):
            if index + i in self.memo:
                if self.memo[index + i]:
                    return True
            else:
                self.memo[index + i] = self.check(index + i)
                if self.memo[index + i]:
                    return True

        return False


    def canJump(self, nums: List[int]) -> bool:
        self.last_index = len(nums) - 1
        self.memo = {}
        self.nums = nums
        return self.check(0)

            
        
            
classes = [[1,2],[3,5],[2,2]]
extraStudents = 2
sol = Solution()
print(f"canJump: {sol.canJump([2,3,1,1,4])}")