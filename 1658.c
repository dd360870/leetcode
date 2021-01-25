#include <stdio.h>
#include <stdlib.h>

int sum_arr (int* arr, int size) {
    int sum = 0;
    for (int i=0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int minOperations_v1(int* nums, int numsSize, int x){
    int num = sum_arr(nums, numsSize) - x;    
    if (num < 0) {
        return -1;
    }
    if (num == 0) {
        return numsSize;
    }
    int min_op = -1; //default value
    for (int i=0;i<numsSize;i++) {
        int tmp = 0;
        for (int j=i; j<numsSize; j++) {
            tmp += nums[j];
            if (tmp == num) {
                int op = numsSize - (j - i + 1);
                if (min_op == -1 || op < min_op) {
                    min_op = op;
                    break;
                }
            }
            else if (tmp > num) {
                // invalid
                break;
            }
        }
    }
    return min_op;
}

int minOperations_v2(int* nums, int numsSize, int x) {
    int target = sum_arr(nums, numsSize) - x;
    if (target < 0) return -1;
    if (target == 0) return numsSize;

    int left = 0;
    int sum = 0;
    int answer = -1;

    for (int i=0;i<numsSize;i++) {
        sum+=nums[i];
        while (sum >= target) {
            if (sum == target) {
                // find max step for target
                int step = i-left+1;
                if (step > answer) {
                    answer = step;
                }
            }
            sum -= nums[left++];
        }
    }
    if (answer == -1) {
        return answer;
    }
    return numsSize - answer;
}

void check(int output, int expected) {
    if (output == expected) {
        printf("pass \n");
    } else {
        printf("failed (expected:%d, output:%d)\n", expected, output);
    }
}

int main(void) {
    int arr[10];
    int r = 0;

    arr[0]=1;arr[1]=2,arr[2]=3;
    r = minOperations_v2(arr, 3, 4);
    check(r, 2);

    arr[0]=1;arr[1]=1;arr[2]=4;arr[3]=2;arr[4]=3;
    r = minOperations_v2(arr, 5, 5);
    check(r, 2);

    arr[0]=1;arr[1]=2;arr[2]=3;arr[3]=4;arr[4]=5;arr[5]=6;arr[6]=7;
    r = minOperations_v2(arr, 7, 7);
    check(r, 1);
}
