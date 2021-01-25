#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int reverse(int x){
    if (-10 < x && x < 10) {
        return x;
    }
    int ans = 0;
    while (x != 0) {
        int pop = x%10;
        x /= 10;
        if (ans > INT_MAX/10 || (ans == INT_MAX/10 && pop > 7)) return 0;
        if (ans < INT_MIN/10 || (ans == INT_MIN/10 && pop < -8)) return 0;
        ans = ans*10 + pop;
    }
    return ans;
}

int main(void) {
    printf("%d\n", INT_MAX);
    printf("%d\n", reverse(7463847412));
    printf("%d\n", reverse(2147483647));
    printf("%d\n", reverse(-2147483648));
}