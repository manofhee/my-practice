from typing import List

# https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def countDigits(self, x):
        count = 0
        while int(x):
            count += 1
            x = int(x / 10)
        return count

    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x == 0:
            return True
        n = self.countDigits(x)
        msd_mask = int(10**(n-1))
        for i in range(int(n/2)):
            if (x % 10) != int(x / msd_mask):
                return False
            x %= msd_mask
            x = int(x / 10)
            msd_mask = int(msd_mask / 100)
        return True

            
classes = [[1,2],[3,5],[2,2]]
extraStudents = 2
sol = Solution()
print(f"isPalindrome: {sol.isPalindrome(1001)}")