//You are given coins of different denominations and a total amount of money amo
//unt. Write a function to compute the fewest number of coins that you need to mak
//e up that amount. If that amount of money cannot be made up by any combination o
//f the coins, return -1. 
//
// Example 1: 
//
// 
//Input: coins = [1, 2, 5], amount = 11
//Output: 3 
//Explanation: 11 = 5 + 5 + 1 
//
// Example 2: 
//
// 
//Input: coins = [2], amount = 3
//Output: -1
// 
//
// Note: 
//You may assume that you have an infinite number of each kind of coin. 
// Related Topics 动态规划


#include "assert.h"
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static int coinChange(vector<int>& coins, int amount) {

        vector<int>dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i ++) {
            for (int coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    vector<int>(coins) = {1, 2, 5};
    int amount = 11;
    assert(Solution::coinChange(coins, amount) == 3);

    //solution.XXX
    return 0;
}