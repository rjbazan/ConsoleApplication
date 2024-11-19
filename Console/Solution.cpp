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

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to simplify edge cases
    ListNode dummy;
    ListNode* tail = &dummy;

    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            tail->next = list1;  // Add list1's node
            list1 = list1->next; // Move list1's pointer
        }
        else {
            tail->next = list2;  // Add list2's node
            list2 = list2->next; // Move list2's pointer
        }
        tail = tail->next;  // Move the tail pointer
    }

    // Attach the remaining nodes of the non-empty list
    if (list1 != nullptr) {
        tail->next = list1;
    }
    else {
        tail->next = list2;
    }

    return dummy.next;  // The merged list starts from dummy.next
}

int Solution::romanToInt(std::string s) {
    std::unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        int current = romanMap[s[i]];
        int next = (i + 1 < n) ? romanMap[s[i + 1]] : 0;

        if (current < next) {
            // Subtraction case
            total -= current;
        }
        else {
            // Addition case
            total += current;
        }
    }
    return total;
}