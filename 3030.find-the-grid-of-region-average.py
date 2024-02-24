#
# @lc app=leetcode id=3030 lang=python3
#
# [3030] Find the Grid of Region Average
#

import math

# @lc code=start
class Solution:
    def resultGrid(self, image: list[list[int]], threshold: int) -> list[list[int]]:
        height = len(image)
        width = len(image[0])

        n = list( ([0] * width) for _ in range(height))
        d = list( ([0] * width) for _ in range(height))

        for i in range(1, height-1):
            for j in range(1, width-1):
                if self.testGrid(image, i, j, threshold):
                    v = self.avgGrid(image, i, j)
                    self.assign(n, d, i, j, v)

        # do averge
        for i in range(0, height):
            for j in range(0, width):
                n[i][j] = math.floor(n[i][j] / d[i][j]) if d[i][j] > 0 else image[i][j]

        return n

    def assign(self, n, d, i, j, value):
        for x in range(i-1, i+2):
            for y in range(j-1, j+2):
                n[x][y] += value
                d[x][y] += 1

    def avgGrid(self, image, i, j) -> int:
        sum = 0
        for x in range(i-1, i+2):
            for y in range(j-1, j+2):
                sum += image[x][y]
        return math.floor(sum / 9)

    def testGrid(self, image, i, j, threshold):
        for x in range(-1, 2):
            for y in range(-1, 1):
                if abs(image[i+x][j+y] - image[i+x][j+y+1]) > threshold:
                    return False
                if abs(image[i+y][j+x] - image[i+y+1][j+x]) > threshold:
                    return False
        return True
        
# @lc code=end

def test(image, thres, exp):
    s = Solution()
    d = s.resultGrid(image, thres)

    print('------ testcase ------')
    print('ans=', d)
    print('exp=', exp)

test([[5,6,7,10],[8,9,10,10],[11,12,13,10]], 3, [[9,9,9,9],[9,9,9,9],[9,9,9,9]])
test([[4,8,5],[5,7,7],[9,4,2]], 4, [[4,8,5],[5,7,7],[9,4,2]])