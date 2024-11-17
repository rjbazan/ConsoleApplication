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