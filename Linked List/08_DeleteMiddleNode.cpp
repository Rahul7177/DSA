#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* target = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            target = slow;
            slow = slow->next;
        }
        target->next = slow->next;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.deleteMiddle(head);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
