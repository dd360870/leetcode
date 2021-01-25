#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) {
        return numsSize;
    }
    int left_index = 0;

    for (int i=1;i<numsSize;i++) {
        if (nums[left_index] != nums[i]) {
            nums[++left_index] = nums[i];
        }
    }
    return left_index + 1;
}

int main(void) {
    int test1[5] = {1, 1, 2};
    int r_len = removeDuplicates(test1, 3);

    for (int i=0; i<r_len; i++) {
        printf("%d\n", test1[i]);
    }
}
