/*There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.*/


// Node class for a linked list
#include <bits/stdc++.h>

using namespace std;
class Node {
public:
    int data;         
    Node* next;     
    
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteTail(Node* head) {
    
    if (head == NULL || head->next == NULL)
        return NULL;
   
    Node* temp = head;
    
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
   
    delete temp->next;
   
    temp->next = nullptr;
    
    return head;
}
int main() {
    
    vector<int> arr = {12, 5, 8, 7};
    
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
   
    head = deleteTail(head);
    
    printLL(head);
}
