#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    bool cmp(vector<int> a, vector<int> b){ return a[0] < b[0]; }
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 1) {
            return 1;
        }

        sort(points.begin(), points.end(), cmp);

        int res = 1, l = points[0][0], h = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if ((points[i][0] < l && points[i][1] < l) || (h < points[i][0] && h < points[i][1])) {
                l = points[i][0];
                h = points[i][1];
                res++;
            }
            else {
                l = max(l, points[i][0]);
                h = min(h, points[i][1]);
            }
        }

        return res;
    }
};
// @lc code=end

void test(vector<vector<int>>& points, int expected) {
    Solution s;
    int res = s.findMinArrowShots(points);
    cout << (res == expected ? "pass " : "failed ") << res << " " << expected << endl;
}

int main(void) {
    vector<vector<int>> d = {{10,16},{2,8},{1,6},{7,12}};
    test(d, 2);
    d = {{1,2},{3,4},{5,6},{7,8}};
    test(d, 4);
    d = {{1,2},{2,3},{3,4},{4,5}};
    test(d, 2);
}
