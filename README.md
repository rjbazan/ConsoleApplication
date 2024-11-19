# Solution Class

This repository contains solutions for various problems implemented in C++. Below are the methods available in the `Solution` class defined in [Solution.h](Solution.h).

## Methods

### 1. `merge`
Merges two integer arrays into one sorted array.


`static void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n);`


### 2. `removeElement`
Given an integer array nums and an integer val, remove all occurrences of val in nums in - place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things :
Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.
Return k.


`static int removeElement(std::vector<int>& nums, int val);`

### 3. `mergeTwoLists`
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.


`static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);`

