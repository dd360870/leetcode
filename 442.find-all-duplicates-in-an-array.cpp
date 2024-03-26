#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        int j;
        vector<int> res;
        for (int i = 0; i < size; i++) {
            j = abs(nums[i])-1;
            if (nums[j] < 0) {
                res.push_back(j+1);
            }
            nums[j] = -nums[j];
        }
        return res;
    }
};
// @lc code=end

