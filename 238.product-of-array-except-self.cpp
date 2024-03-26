#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();

        int left = 1;
        int right = 1;
        vector<int> res(len, 1);

        for (int i = 0; i < len; i++) {
            left *= nums[i];
            right *= nums[len-1-i];
            if ((i+1)<len) {
                res[i+1] *= left;
            }
            
            if ((len-2-i) >= 0) {
                res[len-2-i] *= right;
            }
        }
        return res;
    }
};
// @lc code=end


int main(void) {
    Solution s;

    vector<int> d1 = {1,2,3,4};
    vector<int> res = s.productExceptSelf(d1);

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}