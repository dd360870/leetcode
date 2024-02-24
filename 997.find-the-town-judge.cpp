/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (n <= 1) {
            return n;
        }

        vector<int> trust_count(n+1, 0);
        vector<int> be_trusted_count(n+1, 0);

        for (int i = 0; i < trust.size(); i++) {
            be_trusted_count[trust[i][0]]--;   
            be_trusted_count[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (be_trusted_count[i] == n-1 && trust_count[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

void test(int n, vector<vector<int>>& trust, int exp) {
    cout << "----- testcase -----" << endl;

    Solution s;
    int res = s.findJudge(n, trust);

    cout << "ans= " << res << endl;
    cout << "exp= " << exp << endl;
}

int main() {
    vector<vector<int>> t1 {{1,2}};
    test(2, t1, 2);

    vector<vector<int>> t2 {{1,3},{2,3}};
    test(3, t2, 3);

    vector<vector<int>> t3 {{1,3},{2,3},{3,1}};
    test(3, t3, -1);

    vector<vector<int>> t4 {{1,2},{1,3},{1,4},{2,3},{3,4}};
    test(4, t4, -1);

    vector<vector<int>> t5 {};
    test(1, t5, 1);

    vector<vector<int>> t6 {{1,2},{3,2},{4,2},{5,2}};
    test(6, t6, -1);

    vector<vector<int>> t7 {{1,3},{1,4},{2,3},{2,4},{4,3}};
    test(4, t7, 3);
}