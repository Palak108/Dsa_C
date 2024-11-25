#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int total = numsSize * (numsSize + 1) / 2;
    for (int i = 0; i < numsSize; i++)
        total -= nums[i];
    return total;
}

int main() {
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Missing Number: %d\n", missingNumber(nums, numsSize));
    return 0;
}
