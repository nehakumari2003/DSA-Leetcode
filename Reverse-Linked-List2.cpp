/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void reverse(Node* &head, Node* curr, Node* prev) {
    // Base Case
    if (curr == NULL) {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node* reverseLinkedList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;


    cout << "Original linked list: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

 
    head = reverseLinkedList(head);

 
    cout << "Reversed linked list: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    
    temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
