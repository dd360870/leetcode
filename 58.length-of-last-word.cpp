#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = -1, end = -1;

        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || s[i-1] == ' ') && s[i] != ' ') {
                start = i;
            }
            if ((i == s.size()-1 || s[i+1] == ' ') && s[i] != ' ') {
                end = i;
            }
        }
        return end-start+1;
    }
};
// @lc code=end

