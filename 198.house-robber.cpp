#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(3 + nums.size());

        for (int i = 3; i < dp.size(); i++) {
            dp[i] += nums[i-3] + max(dp[i-2], dp[i-3]);
        }
        return max(dp[dp.size() - 2], dp[dp.size() - 1]);
    }
};
// @lc code=end

void test(vector<int> nums, int exp) {
    Solution s;
    s.rob(nums);
}

int main(void) {
    test(vector<int> {1,2,3,1}, 4);
}
