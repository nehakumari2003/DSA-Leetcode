/*Problem statement
You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

For example :
Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.*/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;


class Node {
public:
    int data;
    Node *next;

  
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


Node *removeDuplicates(Node *head) {
    if (head == nullptr)
        return nullptr;

    unordered_set<int> seen;
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
           
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
           
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }

    return head;
}


void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 3 -> 2 -> 3 -> 4 -> 2 -> 3
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);

    cout << "Original Linked List: ";
    printLinkedList(head);

  
    head = removeDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    printLinkedList(head);


    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
