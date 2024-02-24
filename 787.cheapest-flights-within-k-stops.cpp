/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

/*
沒辦法用dijkstra因為有stop數量限制
用 bfs 直接嘗試所有路徑

1. 用 bfs 嘗試會導致 TLE
*/

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<map<int, int>> f(n);
        for (auto i : flights) {
            f[i[0]][i[1]] = i[2];
        }

        vector<int> d(n, INT_MAX);
        d[src] = 0;
        
        vector<int> d_temp(n);

        queue<int> q;
        q.push(src);

        for (int stops = 0; stops <= k; stops++) {
            int size = q.size();

            d_temp.assign(d.begin(), d.end());

            while (--size >= 0) {
                int node = q.front();
                q.pop();

                // childs
                for (auto i : f[node]) {
                    //cout << stops << " -> " << i.first << endl;
                    if (d[node] != INT_MAX && (d[node] + i.second < d_temp[i.first])) {
                        d_temp[i.first] = d[node] + i.second;
                        q.push(i.first);
                    }
                }
            }

            d.assign(d_temp.begin(), d_temp.end());
        }

        return d[dst] == INT_MAX ? -1 : d[dst];
    }
    
};
// @lc code=end

void test(int n, vector<vector<int>>& flights, int src, int dst, int k, int exp) {
    cout << "----- testcase ------" << endl;
    Solution s;
    int res = s.findCheapestPrice(n, flights, src, dst, k);
    cout << "res= " << res << endl;
    cout << "exp= " << exp << endl;
}

int main() {
    vector<vector<int>> d1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    test(4, d1, 0, 3, 1, 700);

    vector<vector<int>> d2 = {{0,1,100},{1,2,100},{0,2,500}};
    test(3, d2, 0, 2, 1, 200);

    vector<vector<int>> d3 = {{0,1,100},{1,2,100},{0,2,500}};
    test(3, d3, 0, 2, 0, 500);

    vector<vector<int>> d4 = {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
    test(10, d4, 6, 0, 7, 14);

    vector<vector<int>> d5 = {{0,1,2},{0,2,1},{1,3,1},{2,3,1}};
    test(4, d5, 0, 3, 1, 2);

    vector<vector<int>> d6 = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    test(4, d6, 0, 3, 1, 6);

}

