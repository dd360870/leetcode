#include <iostream>
#include <cstdlib>
#include <cmath>

/*
204. Count Primes
*/
class Solution {
public:
    int countPrimes(int n) {
        bool *map = (bool *) calloc(n, sizeof(bool));
        for (int i=2;i<sqrt(n);i++) {
            if (map[i]) {
                continue;
            }
            for (int j=i*i; j<n; j+=i) {
                map[j] = true;
            }
        }
        int count = 0;
        for (int i=2; i<n; i++) {
            if (!map[i]) {
                count++;
            }
        }
        free(map);
        return count;
    }
};

int main(void) {
    Solution s = Solution();
    std::cout << s.countPrimes(100) << "\n";
}