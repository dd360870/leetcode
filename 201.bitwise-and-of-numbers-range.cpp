/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

#include <iostream>

using namespace std;

/*
3: 0011
4: 0100
5: 0101
6: 0110
7: 0111
8: 1000

32: 100000
33: 100001
34: 100010
35: 100011
36: 100100
37: 100101
38: 100110
39: 100111
40: 101000
41: 101001
42: 101010
43: 101011
44: 101100
45: 101101
46: 101110
47: 101111
48: 110000



*/

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int n = 0;
        for (int i = 30; i >= 0; i--) {

            bool left_status = (left & (1 << i));
            bool right_status = (right & (1 << i));

            if (left_status != right_status) {
                break;
            }
            if (left_status) {
                n |= (1 << i);
            }
        }
        return n;
    }
};
// @lc code=end

void test(int left, int right, int exp) {
    cout << "----- testcase (" << left << "," << right << ") -----" << endl;
    Solution s;
    int res = s.rangeBitwiseAnd(left, right);
    cout << "ans= " << res << endl;
    cout << "exp= " << exp << endl;
}

int main(void) {
    test(5, 7, 4);
    test(0, 0, 0);
    test(1, 2147483647, 0);
    test(3, 3, 3);
    test(5, 5, 5);
    test(6, 7, 6);
    test(44, 47, 44);
}
