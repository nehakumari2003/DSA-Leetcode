/*Problem statement
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;


    Node() : data(0), next(nullptr) {}


    Node(int data) : data(data), next(nullptr) {}


    Node(int data, Node* next) : data(data), next(next) {}
};


Node* sortList(Node* head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) {
            zeroCount++;
        } else if (temp->data == 1) {
            oneCount++;
        } else if (temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr) {
        if (zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        } else if (oneCount != 0) {
            temp->data = 1;
            oneCount--;
        } else if (twoCount != 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    printList(head);


    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

 
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
