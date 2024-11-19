#pragma once

#include <vector>
#include <unordered_map>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// You are given two integer arrays nums1 and nums2, sorted in non - decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
	// Merge nums1 and nums2 into a single array sorted in non - decreasing order.
	// The final sorted array should not be returned by the function, but instead be stored inside the array nums1.To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.nums2 has a length of n.
	//
	static void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n);

	// Given an integer array nums and an integer val, remove all occurrences of val in nums in - place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.
	// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things :
	// Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.
	// Return k.
	static int removeElement(std::vector<int>& nums, int val);

	// You are given the heads of two sorted linked lists list1 and list2.
	// Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
	// Return the head of the merged linked list.
	static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

	static int romanToInt(std::string s);
};