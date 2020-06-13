//Given an integer array nums, find the contiguous subarray (containing at least
// one number) which has the largest sum and return its sum. 
//
// Example: 
//
// 
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
// 
//
// Follow up: 
//
// If you have figured out the O(n) solution, try coding another solution using 
//the divide and conquer approach, which is more subtle. 
// Related Topics 数组 分治算法 动态规划

#include "assert.h"
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int dp_0 = nums[0];
        int dp_1 = 0, res = dp_0;

        for (int i = 1; i < nums.size(); i ++) {
            dp_1 = max(nums[i], nums[i] + dp_0);
            dp_0 = dp_1;
            res = max(res, dp_1);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    vector<int>nums1{-2,1,-3,4,-1,2,1,-5,4};
    assert(Solution::maxSubArray(nums1) == 6);

    vector<int>nums2{-1};
    assert(Solution::maxSubArray(nums2) == -1);
    //solution.XXX
    return 0;
}