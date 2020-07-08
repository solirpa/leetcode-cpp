//Given an array nums, there is a sliding window of size k which is moving from 
//the very left of the array to the very right. You can only see the k numbers in 
//the window. Each time the sliding window moves right by one position. Return the
// max sliding window. 
//
// Follow up: 
//Could you solve it in linear time? 
//
// Example: 
//
// 
//Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
//Output: [3,3,5,5,6,7] 
//Explanation: 
//
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window


#include "assert.h"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    class MonotonicQueue {
    private:
        deque<int> data;
    public:
        void push(int n) {
            while (!data.empty() && data.back() < n) {
                data.pop_back();
            }
            data.push_back(n);
        }

        int max() { return data.front(); }

        void pop(int n) {
            if (!data.empty() && data.front() == n) {
                data.pop_front();
            }
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;

        for (int i = 0; i < nums.size(); i ++) {
            if (i < k - 1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    vector<int>input{1,3,-1,-3,5,3,6,7};
    vector<int>output{3,3,5,5,6,7};
    assert(solution.maxSlidingWindow(input, 3) == output);

    return 0;
}