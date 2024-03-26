#include <bits/stdc++.h>

using namespace std;

/*

0100110
 ^^^^^^
 1  23
1 23  4

010010000
0010001110

100011110000

0100000101
      ^^^^


*/

/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(const vector<int>& nums) {
        unordered_map<int, int> first;

        int count = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += (nums[i] == 0) ? -1 : 1;
            if (count == 0 && i > res) {
                res = i+1;
            }
            else if (first.find(count) == first.end()) {
                first[count] = i;
            }
            else if ((i - first[count]) > res) {
                res = i - first[count];
            }
        }
        return res;
    }
};
// @lc code=end

int main(void) {
    Solution s;

    int res = s.findMaxLength(vector<int> {0,1,0,0,1});
    cout << res << endl;
}
