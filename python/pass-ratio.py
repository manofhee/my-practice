from typing import List

# https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15

class Solution:
    def calGain(self, one):
        cur_rate = one[0] / one[1]
        potential = (one[0] +1 )/ (one[1] + 1)
        return potential - cur_rate

    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        passrates = []
        result = 0.0
        for one in classes:
            one.append(self.calGain(one))
            passrates.append(one)
        # passrates.sort()
        passrates = sorted(passrates, key=lambda x: x[2])

        for i in range(extraStudents):
            passrates[-1][0] += 1
            passrates[-1][1] += 1
            passrates[-1][2] = self.calGain(passrates[-1])
            passrates = sorted(passrates, key=lambda x: x[2])
        
        for one in passrates:
            result += (one[0] / one[1])
        return result / len(passrates)
            
classes = [[1,2],[3,5],[2,2]]
extraStudents = 2
sol = Solution()
print(f"pass rate: {sol.maxAverageRatio(classes, extraStudents)}")