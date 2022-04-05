//////You are given two non-empty linked lists representing two non-negative 
//////integers. The digits are stored in reverse order, and each of their nodes 
//
////contains a 
//////single digit. Add the two numbers and return the sum as a linked list. 
//////
////// You may assume the two numbers do not contain any leading zero, except 
//the 
////
//////number 0 itself. 
//////
////// 
////// Example 1: 
//////
////// 
//////Input: l1 = [2,4,3], l2 = [5,6,4]
//////Output: [7,0,8]
//////Explanation: 342 + 465 = 807.
////// 
//////
////// Example 2: 
//////
////// 
//////Input: l1 = [0], l2 = [0]
//////Output: [0]
////// 
//////
////// Example 3: 
//////
////// 
//////Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//////Output: [8,9,9,9,0,0,0,1]
////// 
//////
////// 
////// Constraints: 
//////
////// 
////// The number of nodes in each linked list is in the range [1, 100]. 
////// 0 <= Node.val <= 9 
////// It is guaranteed that the list represents a number that does not have 
//////leading zeros. 
////// 
////// Related Topics 递归 链表 数学 👍 7835 👎 0
////
//

#include <cassert>
#include "listnode.hpp"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* pre = new ListNode(0);
        ListNode* cur = pre;
        int curry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = curry + x + y;

            curry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        if (curry == 1) {
            cur->next = new ListNode(curry);
        }

        return pre->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    auto l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    auto* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    auto* l3 = Solution::addTwoNumbers(l1, l2);
    assert(compare(l3, new ListNode(7, new ListNode(0, new ListNode(8)))) == true);

    //solution.XXX
    return 0;
}
