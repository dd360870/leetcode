#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
[00000]
*/


/*
[0010101]
----------1
 0
----------2
 00
  0
----------3
   1
  01
 001
----------4
    0
   10
  010
 0010
----------5
     1
    01
   101
  0101
 00101
----------6
      0
     10
    010
   1010
  01010
 001010
----------4
       1
      01
     101
    0101

*/

/*
[10101]
 1
  0
 10
   1
  01
 101
    0
   10
  010
 1010
     1
    01
   101
  0101
 
*/

/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public:
    int subset(vector<int>& nums, int goal) {

        int i = 0, j = 0, sum = 0, count = 0;

        for (j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum > goal && i <= j) {
                sum -= nums[i];
                i++;
            }
            count += (j-i+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subset(nums, goal) - subset(nums, goal-1);
    }
};
// @lc code=end


int main(void) {
    Solution s;

    vector<int> d1 = {1,0,1,0,1};
    printf("%d (%d)\n", s.numSubarraysWithSum(d1, 2), 4);

    vector<int> d2 = {0,0,0,0,0};
    printf("%d (%d)\n", s.numSubarraysWithSum(d2, 0), 15);

    vector<int> d3 = {0,0,0,0,1,0,1,0,0};
    printf("%d (%d)\n", s.numSubarraysWithSum(d3, 3), 0);

    vector<int> d4 = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
    printf("%d (%d)\n", s.numSubarraysWithSum(d4, 3), 48);
}
