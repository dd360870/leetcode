#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int s = 0; // keep track of non-zero items in unordered_map m.
        int i = 0, j = 0, ans = 0;
        int prev = 0;
        for (;j < nums.size(); j++) {
            if (m[nums[j]]++ == 0) {
                s++;
            }
            // move to minium subarray (i, j)
            while (m[nums[i]] > 1) {
                m[nums[i++]]--;
            }
            if (s == k) {
                //cout << i << " " << j << " " << i-prev+1 << endl;
                ans += i-prev+1;
            }
            // new number -> make s < k
            if (s == k && j+1 < nums.size() && m[nums[j+1]] == 0) {
                while (i <= j && s == k) {
                    m[nums[i]]--;
                    if (m[nums[i]] == 0) {
                        s--;
                    }
                    i++;
                }
                prev = i;
            }
        }
        return ans;
    }
};
// @lc code=end

void test(vector<int> nums, int k, int exp) {
    Solution s;
    int res = s.subarraysWithKDistinct(nums, k);
    cout << ((res == exp) ? "pass" : "failed") << " " << exp << " " << res << endl;
}

int main(void) {
    test(vector<int> {1,2,1,2,3}, 2, 7);
    test(vector<int> {1,2,1,3,4}, 3, 3);
    test(vector<int> {1,2,2,2,1,3}, 2, 8);
    //test(vector<int> {}, , );
    //test(vector<int> {}, , );
    //test(vector<int> {}, , );
}
