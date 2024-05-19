/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* temp = new Node(val);
        // Empty list
        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    Node* add(Node* first, Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while (first != NULL || second != NULL || carry != 0) {
            int val1 = 0;
            if (first != NULL)
                val1 = first->data;
                
            int val2 = 0;
            if (second != NULL)
                val2 = second->data;
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            // Create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            if (first != NULL)
                first = first->next;
            
            if (second != NULL)
                second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1 - Reverse input linked lists
        first = reverse(first);
        second = reverse(second);
        
        // Step 2 - Add the two linked lists
        Node* ans = add(first, second);
        
        // Step 3 - Reverse the result linked list
        ans = reverse(ans);
        
        return ans;
    }
};

// Helper functions for testing
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two lists
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(3);

    Node* second = new Node(5);
    second->next = new Node(6);
    second->next->next = new Node(4);

    Solution solution;
    Node* result = solution.addTwoLists(first, second);

    // Print result
    printList(result);

    return 0;
}
