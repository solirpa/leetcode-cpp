//You are given K eggs, and you have access to a building with N floors from 1 t
//o N. 
//
// Each egg is identical in function, and if an egg breaks, you cannot drop it a
//gain. 
//
// You know that there exists a floor F with 0 <= F <= N such that any egg dropp
//ed at a floor higher than F will break, and any egg dropped at or below floor F 
//will not break. 
//
// Each move, you may take an egg (if you have an unbroken one) and drop it from
// any floor X (with 1 <= X <= N). 
//
// Your goal is to know with certainty what the value of F is. 
//
// What is the minimum number of moves that you need to know with certainty what
// F is, regardless of the initial value of F? 
//
// 
//
// 
// 
//
// 
// Example 1: 
//
// 
//Input: K = 1, N = 2
//Output: 2
//Explanation: 
//Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
//Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty th
//at F = 1.
//If it didn't break, then we know with certainty F = 2.
//Hence, we needed 2 moves in the worst case to know what F is with certainty.
// 
//
// 
// Example 2: 
//
// 
//Input: K = 2, N = 6
//Output: 3
// 
//
// 
// Example 3: 
//
// 
//Input: K = 3, N = 14
//Output: 4
// 
//
// 
//
// Note: 
//
// 
// 1 <= K <= 100 
// 1 <= N <= 10000 
// 
// 
// 
// 
// Related Topics 数学 二分查找 动态规划

#include "assert.h"
#include <iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    unordered_map<int, int> memo;

    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans = N + 1;
            if (K == 1) {
                ans = N;
            } else if (N == 0) {
                ans = 0;
            } else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }

                ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                              max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo[N * 100 + K] = ans;
            return ans;
        }

        return memo[N * 100 + K];
    }

public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    assert(solution.superEggDrop(2, 6) == 3);
    assert(solution.superEggDrop(3, 14) == 4);
    assert(solution.superEggDrop(1, 3) == 3);
    return 0;
}