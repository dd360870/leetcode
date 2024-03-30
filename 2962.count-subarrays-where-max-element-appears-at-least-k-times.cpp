#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = *max_element(nums.begin(), nums.end());
        int size = nums.size();

        int i = 0, j = 0, cnt = 0;
        long long ans = 0;

        for (; j < size; j++) {
            if (nums[j] == n) {
                cnt++;
            }
            while (cnt > k || (i <= j and cnt == k and nums[i] != n)) {
                if (nums[i] == n) {
                    cnt--;
                }
                i++;
            }
            if (cnt == k) {
                ans += (i+1);
            }
        }
        return ans;
    }
};
// @lc code=end
