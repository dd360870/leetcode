#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;

    char **r = malloc(sizeof(char *) * n);
    char buf[10];
    for (int i=0; i<n; i++) {
        int num = i+1;
        if (num % 15 == 0) {
            sprintf(buf, "%s", "FizzBuzz");
        }
        else if (num % 3 == 0) {
            sprintf(buf, "%s", "Fizz");
        }
        else if (num % 5 == 0) {
            sprintf(buf, "%s", "Buzz");
        }
        else {
            sprintf(buf, "%d", num);
        }
        int size = sizeof(char) * (strlen(buf) + 1);
        r[i] = malloc(size);
        memcpy(r[i], buf, size);
    }

    return r;
}

int main(void) {
    int n;
    char **arr = fizzBuzz(15, &n);
    printf("%ld\n", sizeof(arr));
    for (int i=0;i<n;i++) {
        printf("%2d: %s\n", i, arr[i]);
    }
    free(arr);
}