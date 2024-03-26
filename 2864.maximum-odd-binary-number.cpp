/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count_one = 0;
        for (auto c : s) {
            if (c == '1') {
                count_one++;
            }
        }
        string res(s.length(), '0');

        for (int i = 0; i < count_one -1; i++) {
            res[i] = '1';
        }
        res[s.length() - 1] = '1';
        return res;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    s.maximumOddBinaryNumber("10001");
}
