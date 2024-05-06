/*Problem statement
Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

For example:
The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
Follow Up :
Can you solve this problem in O(N) time and O(1) space complexity?*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = nullptr;

    while (curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main() {
    
    LinkedListNode<int>* head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    cout << "Original list: ";
    LinkedListNode<int>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    
    head = reverseLinkedList(head);

    cout << "Reversed list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    
    temp = head;
    while (temp != nullptr) {
        LinkedListNode<int>* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
