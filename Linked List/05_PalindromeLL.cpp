#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfStart = reverse(slow);
        ListNode* firstHalf = head;
        ListNode* secondHalf = secondHalfStart;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    Solution sol;
    bool result1 = sol.isPalindrome(head1);
    bool result2 = sol.isPalindrome(head2);

    cout << (result1 ? "true" : "false") << endl;
    cout << (result2 ? "true" : "false") << endl;

    return 0;
}
