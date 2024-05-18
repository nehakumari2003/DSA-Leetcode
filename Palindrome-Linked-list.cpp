/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
private:

    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }


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

public:

    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // Step 1: Find the middle of the linked list
        Node* middle = getMid(head);

        // Step 2: Reverse the second half of the linked list
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while (head2 != NULL) {
            if (head1->data != head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

      
        middle->next = reverse(middle->next);

        return true;
    }
};


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    printList(head);

    return 0;
}
