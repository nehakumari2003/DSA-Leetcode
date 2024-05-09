/*Problem statement
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.
For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.
Implement a function that performs this reversal, and returns the head of the modified linked list.
Example:
Input: 'list' = [1, 2, 3, 4], 'k' = 2
Output: 2 1 4 3*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // Check if there are at least k nodes remaining
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == nullptr) {
                return head; // If less than k nodes remaining, return head
            }
            temp = temp->next;
        }
        
        // Reverse the first k nodes
        ListNode *next = nullptr;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        int count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // Recursive call for the next group
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }
        
        // Return the new head of the reversed group
        return prev;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 3;
    cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = solution.reverseKGroup(head, k);

    cout << "Reversed list in groups of " << k << ": ";
    printList(reversedHead);

    // Clean up memory
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
