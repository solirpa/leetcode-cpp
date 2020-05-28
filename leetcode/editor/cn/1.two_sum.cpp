//Given an array of integers, return indices of the two numbers such that they a
//dd up to a specific target. 
//
// You may assume that each input would have exactly one solution, and you may n
//ot use the same element twice. 
//
// Example: 
//
// 
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
// 
// Related Topics 数组 哈希表


#include "assert.h"
#include <unordered_map>
#include <vector>
//leetcode submit region begin(Prohibit modification and deletion)

using namespace std;

class Solution {
public:
    static vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];
            if (map.count(num) > 0){
                res.push_back(map[num]);
                res.push_back(i);
                return res;
            }

            map.insert(make_pair(nums[i], i));
        }

        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    assert((Solution::twoSum(vector<int>{2, 7, 11, 15}, 9) == vector<int>{0, 1}));
    assert((Solution::twoSum(vector<int>{2}, 3) == vector<int>{}));
    //solution.XXX
    return 0;
}