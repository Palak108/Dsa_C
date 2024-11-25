#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[20], ba[20];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    char* result = malloc(1000);
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        char buffer[10];
        sprintf(buffer, "%d", nums[i]);
        strcat(result, buffer);
    }
    return result;
}

int main() {
    int nums[] = {3, 30, 34, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    char* result = largestNumber(nums, numsSize);
    printf("Largest Number: %s\n", result);
    free(result);
    return 0;
}
