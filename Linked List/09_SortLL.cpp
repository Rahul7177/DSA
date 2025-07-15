#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:

    ListNode* findMid(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        return prev;
    }

    ListNode* mergeLL(ListNode* left, ListNode* right)
    {
        // Creating Head of the merged List
        ListNode* merged = new ListNode();
        
        // Pointer Node to build merged List
        ListNode* temp = merged;

        while(left != NULL && right != NULL)
        {
            if(left->val <= right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        while(left != NULL)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }

        while(right != NULL)
        {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }

        merged = merged->next;
        return merged;
    }

    ListNode* sortList(ListNode* head) {
        
        // Base Case : List have Zero or One Element
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        // Dividing LL into two parts

        // Finding middle node
        ListNode* mid = findMid(head);

        // Storing Two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL; // Breaking the link of First & Second Half

        left = sortList(left);
        right = sortList(right);

        // Merging two halves
        ListNode* res = mergeLL(left, right);
        
        return res;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* result = sol.sortList(head);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
