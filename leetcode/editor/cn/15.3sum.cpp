//Given an array nums of n integers, are there elements a, b, c in nums such tha
//t a + b + c = 0? Find all unique triplets in the array which gives the sum of ze
//ro. 
//
// Note: 
//
// The solution set must not contain duplicate triplets. 
//
// Example: 
//
// 
//Given array nums = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针


#include "assert.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        vector<vector<int>>(result);
        sort(nums.begin(),nums.end());

        for (int base = 0; base < nums.size(); base ++) {
            if (nums[base] > 0 || base > nums.size() - 3) return result;

            if (base > 0 && nums[base] == nums[base - 1]) continue;

            int left = base + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[base] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back(vector<int>{nums[base], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (right > left && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }

                if (0 < sum) {
                    right--;
                    continue;
                }

                if (0 > sum) {
                    left++;
                    continue;
                }
            }
        }

        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    vector<int>(nums) = {-1, 0, 1, 2, -1, -4};
    assert((Solution::threeSum(nums) == vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}));
    //solution.XXX
    return 0;
}