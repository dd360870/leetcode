#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int j;

        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0 || nums[i] > size) {
                nums[i] = size + 1;
            }
        }
        for (int i = 0; i < size; i++) {
            j = abs(nums[i])-1;
            if (0 <= j && j < size) {
                nums[j] = -abs(nums[j]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return size + 1;
    }
};
// @lc code=end

void test(vector<int> nums, int expected) {
    Solution s;
    int res = s.firstMissingPositive(nums);
    cout << ((res == expected) ? "pass" : "failed") << " " << res << " " << expected << endl;
}

int main(void) {
    test(vector<int> {1,2,0}, 3);
    test(vector<int> {3,4,-1,1}, 2);
    test(vector<int> {7,8,9,11,12}, 1);
    test(vector<int> {7,7,7,7,7,2,1}, 3);
    test(vector<int> {7,7,7,7,7,7,2,1}, 3);
    test(vector<int> {1,1}, 2);
}