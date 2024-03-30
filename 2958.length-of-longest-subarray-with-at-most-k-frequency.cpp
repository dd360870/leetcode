#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> dict;

        int size = nums.size();

        int i = 0, j = 0 ,res = 0;

        for (; j < size; j++) {
            dict[nums[j]]++;
            while (dict[nums[j]] > k) {
                dict[nums[i]]--;
                i++;
            }
            res = max(res, j-i+1);
        }

        return res;
    }
};
// @lc code=end

void test(vector<int> nums, int k, int expected) {
    Solution s;
    int res = s.maxSubarrayLength(nums, k);
    cout << ((res == expected) ? "pass" : "failed") << " " << expected << " " << res << endl;
}

int main(void) {
    test(vector<int> {1,2,3,1,2,3,1,2}, 2, 6);
    test(vector<int> {1,2,3,1,2,3}, 2, 6);
    test(vector<int> {1,2,1,2,1,2,1,2}, 1, 2);
    test(vector<int> {5,5,5,5,5,5,5}, 4, 4);
    test(vector<int> {4,4,4,1,2,3,1,2,3}, 2, 8);
    test(vector<int> {1,2,3,4,1,2,4,2,3,5,4,2,3,5,2,2,2,1,1}, 3, 12);
}
