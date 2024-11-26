#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    
    // If the array is not rotated
    if (nums[left] < nums[right]) {
        return nums[left];
    }
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Check if the mid element is the minimum
        if (nums[mid] > nums[right]) {
            // Minimum must be in the right half
            left = mid + 1;
        } else {
            // Minimum must be in the left half
            right = mid;
        }
    }
    
    return nums[left];
}

int main() {
    int nums1[] = {3, 4, 5, 1, 2};
    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int nums3[] = {11, 13, 15, 17};
    
    printf("Minimum in nums1: %d\n", findMin(nums1, 5)); // Output: 1
    printf("Minimum in nums2: %d\n", findMin(nums2, 7)); // Output: 0
    printf("Minimum in nums3: %d\n", findMin(nums3, 4)); // Output: 11
    
    return 0;
}
