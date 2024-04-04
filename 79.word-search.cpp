#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> entries;

        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                entries.push_back({i, j});
            }
        }

        for (auto it : entries) {
            auto board_copy(board);

            if (tryRoute(board_copy, word, 0, it.first, it.second)) {
                return true;
            }
        }
        return false;
    }

    bool tryRoute(vector<vector<char>>& board, string& word, int word_idx, int x, int y) {
        if (word_idx >= word.size()) {
            // reach string end
            return true;
        }
        if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size()) {
            // out of range OR char not match
            return false;
        }
        if (word[word_idx] != board[y][x]) {
            return false;
        }

        board[y][x] = '\0';

        bool res = tryRoute(board, word, word_idx+1, x+1, y)
            || tryRoute(board, word, word_idx+1, x, y+1)
            || tryRoute(board, word, word_idx+1, x-1, y)
            || tryRoute(board, word, word_idx+1, x, y-1);

        if (!res) {
            board[y][x] = word[word_idx];
            return false;
        }
        return true;
    }
};
// @lc code=end

void test(vector<vector<char>>& board, string word, bool exp) {
    Solution s;
    bool res = s.exist(board, word);
    cout << ((res == exp) ? "pass" : "failed") << " " << res << " " << exp << endl;
}

int main(void) {
    vector<vector<char>> d1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    test(d1, "ABCB", false);
}
