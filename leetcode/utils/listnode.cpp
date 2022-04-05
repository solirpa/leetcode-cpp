#include "listnode.hpp"

bool compare(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr || l2 == nullptr) {
            return false;
        }

        if (l1->val != l2->val) {
            return false;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    return true;
}