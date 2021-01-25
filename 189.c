#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(int* nums, int numsSize) {
    for (int i=0;i<floor(numsSize/2);i++) {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0 || numsSize == 1 || k == 0) {
        return;
    }
    if (k > numsSize) {
        k %= numsSize;
    }

    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(&nums[k], numsSize-k);
}

int main(void) {
    int test[5] = {1, 2, 3, 4, 5};
    rotate(test, 5, 3);
    for (int i=0;i<5;i++) {
        printf("%d\n", test[i]);
    }
    return 0;
}