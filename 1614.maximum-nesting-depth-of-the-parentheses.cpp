#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int n = 0;
        int ans = 0;

        for (auto it : s) {
            if (it == '(') {
                n++;
                if (n > ans) {
                    ans = n;
                }
            }
            else if (it == ')') {
                n--;
            }
        }
        return ans;
    }
};
// @lc code=end

