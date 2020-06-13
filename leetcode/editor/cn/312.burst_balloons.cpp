//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number
// on it represented by array nums. You are asked to burst all the balloons. If th
//e you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Her
//e left and right are adjacent indices of i. After the burst, the left and right 
//then becomes adjacent. 
//
// Find the maximum coins you can collect by bursting the balloons wisely. 
//
// Note: 
//
// 
// You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can n
//ot burst them. 
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100 
// 
//
// Example: 
//
// 
//Input: [3,1,5,8]
//Output: 167 
//Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
// Related Topics 分治算法 动态规划

#include "assert.h"
#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n + 2, 1);
        for (int i = 1; i <= n; i ++) {
            points[i] = nums[i - 1];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 0; i --) {
            for (int j = i + 1; j < n + 2; j ++) {
                for (int k = i + 1; k < j; k ++) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i][k] + points[i] * points[k] * points[j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    vector<int>coins{3, 1, 5, 8};
    assert(solution.maxCoins(coins) == 167);
    return 0;
}