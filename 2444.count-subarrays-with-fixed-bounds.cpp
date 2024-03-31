#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int jmin = -1, jmax = -1, jbad = -1;
        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < minK || maxK < nums[j]) {
                jbad = j;
            }
            if (nums[j] == minK) {
                jmin = j;
            }
            if (nums[j] == maxK) {
                jmax = j;
            }
            if (jbad < min(jmin, jmax)) {
                ans += min(jmin, jmax) - jbad;
            }
        }
        return ans;
    }
};
// @lc code=end

void test(vector<int> nums, int minK, int maxK, long long expected) {
    Solution s;
    long long res = s.countSubarrays(nums, minK, maxK);
    cout << ((res == expected) ? "pass" : "failed") << " " << expected << " " << res << endl;
}

int main(void) {
    test(vector<int> {1,3,5,2,7,5}, 1, 5, 2);
    test(vector<int> {1,1,1,1}, 1, 1, 10);
    test(vector<int> {1,3,5,2,7,5,1,3,2,5}, 1, 5, 7);
    test(vector<int> {1,2}, 2, 1, 0);
    test(vector<int> {1,1}, 1, 1, 3);
    test(vector<int> {2,2}, 1, 1, 0);
    test(vector<int> {1,1,1,1,1,1,1,1,1,1,10}, 1, 1, 55);
    //test(vector<int> {});
}
