#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            if (a == NULL) {
                a = headB;
            } else {
                a = a->next;
            }
            if (b == NULL) {
                b = headA;
            } else {
                b = b->next;
            }
        }
        return a;
    }
};

int main() {
    // Common part
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
