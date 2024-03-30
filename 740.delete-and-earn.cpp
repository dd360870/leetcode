#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto it : nums) {
            dict[it]++;
        }
        vector<int> s;
        for (auto it : dict) {
            s.push_back(it.first);
        }
        sort(s.begin(), s.end());

        vector<int> dp(s.size());

        dp[0] = s[0] * dict[s[0]];

        for (int i = 1; i < dp.size(); i++) {
            if ((s[i-1]+1) != s[i]) {
                dp[i] = dp[i-1] + s[i] * dict[s[i]];
            }
            else {
                dp[i] = max(dp[i-1], (i >= 2 ? dp[i-2] : 0) + s[i] * dict[s[i]]);
            }
        }
        return dp[dp.size() - 1];
    }
};
// @lc code=end

