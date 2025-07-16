// URL: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// 25. Reverse Nodes in k-Group

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

//  
// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

//  
// Constraints:

// 	The number of nodes in the list is n.
// 	1 <= k <= n <= 5000
// 	0 <= Node.val <= 1000

//  
// Follow-up: Can you solve the problem in O(1) extra memory space?


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

    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* previousNode = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* currentNode = head;

        // Reverse the entire linked list
        while (currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        return previousNode; // New head after reversing
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // If list is empty, has only one node, or k <= 1, no change needed
        if (head == nullptr || head->next == nullptr || k <= 1) {
            return head;
        }

        // Dummy node helps manage changes at the head of the list
        ListNode* dummyNodeBeforeList = new ListNode(0);
        dummyNodeBeforeList->next = head;

        // Pointer to connect the end of previous reversed group to the next
        ListNode* endOfPreviousGroup = dummyNodeBeforeList;

        // Pointer to the start of the group to be reversed
        ListNode* startOfCurrentGroup = head;

        while (startOfCurrentGroup != nullptr) {

            // Find the end of the current group of size k
            ListNode* endOfCurrentGroup = startOfCurrentGroup;
            int count = 1;
            while (count < k && endOfCurrentGroup != nullptr && endOfCurrentGroup->next != nullptr) {
                endOfCurrentGroup = endOfCurrentGroup->next;
                count++;
            }

            // If there are fewer than k nodes remaining, do not reverse
            if (count < k || endOfCurrentGroup == nullptr) {
                break;
            }

            // Store the start of the next group (to connect later)
            ListNode* startOfNextGroup = endOfCurrentGroup->next;

            // Temporarily cut the list to isolate the current k-group
            endOfCurrentGroup->next = nullptr;

            // Reverse the current k-group
            ListNode* newHeadOfReversedGroup = reverseList(startOfCurrentGroup);

            // Connect the previous group to the newly reversed group
            endOfPreviousGroup->next = newHeadOfReversedGroup;

            // Connect the end of the reversed group to the next group
            startOfCurrentGroup->next = startOfNextGroup;

            // Move pointers for the next iteration
            endOfPreviousGroup = startOfCurrentGroup;
            startOfCurrentGroup = startOfNextGroup;
        }

        // Final head is after dummy node
        return dummyNodeBeforeList->next;
    }
};

int main() {
    // Create list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    ListNode* result = sol.reverseKGroup(head, k);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
