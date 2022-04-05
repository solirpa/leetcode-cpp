#ifndef LEETCODE_CPP_LISTNODE_HPP
#define LEETCODE_CPP_LISTNODE_HPP

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

extern "C" bool compare(ListNode* l1, ListNode* l2);

#endif //LEETCODE_CPP_LISTNODE_HPP
