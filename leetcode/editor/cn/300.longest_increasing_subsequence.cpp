//Given an unsorted array of integers, find the length of longest increasing sub
//sequence. 
//
// Example: 
//
// 
//Input: [10,9,2,5,3,7,101,18]
//Output: 4 
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the 
//length is 4. 
//
// Note: 
//
// 
// There may be more than one LIS combination, it is only necessary for you to r
//eturn the length. 
// Your algorithm should run in O(n2) complexity. 
// 
//
// Follow up: Could you improve it to O(n log n) time complexity? 
// Related Topics 二分查找 动态规划


#include "assert.h"
#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static int lengthOfLIS(vector<int> &nums) {
        vector<int>top(nums.size());
        int plies = 0;

        for (int n : nums) {
            int left = 0, right = plies;
            while(left < right) {
                int mid = (left + right) / 2;
                if (top[mid] > n) {
                    right = mid;
                } else if (top[mid] < n) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (left == plies) plies++;
            top[left] = n;
        }

        return plies;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    vector<int>nums{10,9,2,5,3,7,101,18};
    cout << Solution::lengthOfLIS(nums) << endl;
    assert(Solution::lengthOfLIS(nums) == 4);
    return 0;
}