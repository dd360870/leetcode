#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(const vector<vector<int>>& intervals, const vector<int>& newInterval) {
        vector<vector<int>> res;

        int l = newInterval[0], h = newInterval[1];

        int i = 0;

        while (i < intervals.size() && intervals[i][0] < l && intervals[i][1] < l) {
            res.push_back(vector<int> {intervals[i][0], intervals[i][1]});
            i++;
        }

        while (i < intervals.size() && !(h < intervals[i][0] && h < intervals[i][1])) {
            l = min(l, intervals[i][0]);
            h = max(h, intervals[i][1]);
            i++;
        }
        res.push_back(vector<int> {l, h});

        while (i < intervals.size()) {
            res.push_back(vector<int> {intervals[i][0], intervals[i][1]});
            i++;
        }

        return res;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<vector<int>> res;

    res = s.insert(vector<vector<int>> {{1,2},{3,5},{6,7},{8,10},{12,16}}, vector<int> {17, 19});
    res = s.insert(vector<vector<int>> {{1,5}}, vector<int> {2,3});

    return 0;
}
