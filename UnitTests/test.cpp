#include "pch.h"
#include "Console/Solution.cpp"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

//TEST(MergeTest, HandlesBasicMerge) {
//    GameLogic game;
//    std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
//    std::vector<int> nums2 = { 2, 5, 6 };
//    game.displayBoard();  // Call the method to test
//    EXPECT_EQ(1, 1);  // Check that nums1 is correctly merged
//}

TEST(MergeTest, HandlesBasicMerge) {
	Solution solution;
	std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	std::vector<int> nums2 = { 2, 5, 6 };
	solution.merge(nums1, 3, nums2, 3);  // Call the method to test
	EXPECT_EQ(nums1, (std::vector<int>{1, 2, 2, 3, 5, 6}));  // Check that nums1 is correctly merged
}

TEST(RemoveElementTest, HandlesRemoval) {
	Solution solution;
	std::vector<int> nums = { 3, 2, 2, 3 };
	int val = 3;
	int k = solution.removeElement(nums, val);  // Call the method to test
	EXPECT_EQ(k, 2);  // Check that 2 elements remain
	EXPECT_EQ(nums[0], 2);  // First element should be 2
	EXPECT_EQ(nums[1], 2);  // Second element should also be 2
}

// Helper function to compare two linked lists
bool areListsEqual(ListNode* l1, ListNode* l2) {
	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val != l2->val) return false;
		l1 = l1->next;
		l2 = l2->next;
	}
	return l1 == nullptr && l2 == nullptr;  // Both lists should end at the same time
}

// Helper: Create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
	ListNode* dummy = new ListNode();
	ListNode* tail = dummy;

	for (int val : values) {
		tail->next = new ListNode(val);
		tail = tail->next;
	}
	return dummy->next;
}

// Helper: Free linked list memory
void freeList(ListNode* head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST(MergeTwoLists, HandlesMerge) {
	Solution solution;
	// Create two sorted linked lists
	ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

	// Expected merged list: 1 -> 1 -> 2 -> 3 -> 4 -> 4
	ListNode* expected = new ListNode(1,
		new ListNode(1,
			new ListNode(2,
				new ListNode(3,
					new ListNode(4,
						new ListNode(4))))));

	// Merge the two lists
	ListNode* mergedList = solution.mergeTwoLists(list1, list2);

	// Compare the merged list with the expected list
	EXPECT_TRUE(areListsEqual(mergedList, expected));

	freeList(expected);
	freeList(mergedList);
}

TEST(MergeTwoListsCase2, HandlesMerge) {
	Solution solution;
	// Create two sorted linked lists
	ListNode* list1 = createList(std::vector<int>{1, 2, 3});
	ListNode* list2 = createList(std::vector<int>{4, 5});

	// Expected merged list: empty
	ListNode* expected = createList(std::vector<int>{1, 2, 3, 4, 5});

	// Merge the two lists
	ListNode* mergedList = solution.mergeTwoLists(list1, list2);

	// Compare the merged list with the expected list
	EXPECT_TRUE(areListsEqual(mergedList, expected));

	freeList(expected);
	freeList(mergedList);
}

TEST(RomanToIntTest, HandlesBasicConversion) {
	Solution solution;
	std::string roman = "III";  // 1994
	int result = solution.romanToInt(roman);  // Call the method to test
	EXPECT_EQ(result, 1994);
}