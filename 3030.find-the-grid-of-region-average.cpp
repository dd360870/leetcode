/*
 * @lc app=leetcode id=3030 lang=cpp
 *
 * [3030] Find the Grid of Region Average
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int height = image.size();
        int width = image[0].size();

        vector<vector<int>> n(height, vector<int>(width, 0));
        vector<vector<int>> d(height, vector<int>(width, 0));

        for (int i = 1; i < height - 1; i++) {
            for (int j = 1; j < width - 1; j++) {
                if (this->testGrid(image, threshold, i, j)) {
                    int v = this->avgGrid(image, i, j);
                    this->apply(n, d, i, j, v);
                }
            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                image[i][j] = (d[i][j] > 0) ? floor(n[i][j]/d[i][j]) : image[i][j];
            }
        }

        return image;
    }
private:
    void apply(vector<vector<int>>& n, vector<vector<int>>& d, int x, int y, int value) {
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                n[i][j] += value;
                d[i][j]++;
            }
        }
    }
    int avgGrid(vector<vector<int>>& image, int x, int y) {
        int sum = 0;
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                sum += image[i][j];
            }
        }
        return floor(sum/9);
    }
    bool testGrid(vector<vector<int>>& image, int threshold, int x, int y) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 0; j++) {
                if (abs(image[x+i][y+j] - image[x+i][y+j+1]) > threshold || abs(image[x+j][y+i] - image[x+j+1][y+i]) > threshold) {
                    return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    vector<vector<int>> data {{5,6,7,10},{8,9,10,10},{11,12,13,10}};
    Solution s = Solution();
    vector<vector<int>> res = s.resultGrid(data, 3);
    return 0;
}