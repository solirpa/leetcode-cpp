//给你一个可装载重量为 W 的背包和 N 个物品，每个物品有重量和价值两个属性。
// 其中第 i 个物品的重量为 wt[i]，价值为 val[i]，现在让你用这个背包装物品，最多能装的价值是多少？
//
// Example:
//
//
//Input: N = 3, W = 4
//       wt = [2, 1, 3]
//       val = [4, 2, 3]
//Output: 6
//Explanation: wt [2, 1]  val [4, 2]


#include "assert.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    for i in [1..N]:
//      for w in [1..W]:
//          dp[i][w] = max(
//            dp[i-1][w],    不把物品 i 装进背包,
//            dp[i-1][w - wt[i-1]] + val[i-1]    把物品 i 装进背包,
//          )
//    return dp[N][W]

    static int knapsack(int W, int N, vector<int> &wt, vector<int> &val) {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int w = 1; w <= W; w ++) {
                // 这种情况下只能选择不装入背包
                if (w - wt[i - 1] < 0) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // 装入或者不装入背包，择优
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][W - wt[i - 1]] + val[i - 1]);
                }
            }
        }

        return dp[N][W];
    }
};


int main() {
    int W = 4;
    int N = 3;
    vector<int> wt{2, 1, 3};
    vector<int> val{4, 2, 3};

    cout << Solution::knapsack(W, N, wt, val) << endl;

    assert(Solution::knapsack(W, N, wt, val) ==6);
    return 0;
}