#include "Solution.h"

void Solution::merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n)
{
    int p1 = m - 1; // Pointer to the last element in the first m elements of nums1
    int p2 = n - 1; // Pointer to the last element in nums2
    int p = m + n - 1; // Pointer to the last position in nums1 (where the merged array will end)

    // Merge in reverse order
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        }
        else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}

int Solution::removeElement(std::vector<int>& nums, int val)
{
    int k = 0; // Pointer for the next position to place non-val elements

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}