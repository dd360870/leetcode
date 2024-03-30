#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios::sync_with_stdio( false );
        cin.tie( 0 );
        cout.tie( 0 );

        int i = 0, j = 0, p = 1, t;
        int res = 0;

        while (i < nums.size() && i <= j) {
            while (j < nums.size()) {
                t = p * nums[j];
                if (t >= k) {
                    break;
                }
                p = t;
                j++;
            }
            //cout << i << " " << j << " " << res << endl;
            res += j-i;

            if (i == j) {
                i++;
                j++;
            }
            else{
                p /= nums[i];
                i++;
            }
            
        }
        return res;
    }
};
// @lc code=end

void test(vector<int> nums, int k, int expected) {
    Solution s;
    int res = s.numSubarrayProductLessThanK(nums, k);
    cout << ((res == expected) ? "pass" : "failed") << " " << expected << " " << res << endl;
}

int main(void) {
    test(vector<int> {10,5,2,6}, 100, 8);
    test(vector<int> {1,2,3}, 0, 0);
    test(vector<int> {3,6,9,12,1}, 3, 1);
}
