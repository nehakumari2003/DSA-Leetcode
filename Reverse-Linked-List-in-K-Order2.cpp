/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]*/
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
                return head; 
            }
            temp = temp->next;
        }
        
      
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
        
       
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }
        
        
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
