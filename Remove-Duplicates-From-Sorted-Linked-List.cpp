/*A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
You are given a sorted doubly linked list of size 'n'.
Remove all the duplicate nodes present in the linked list.*/
#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructors
    Node() {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};


Node *removeDuplicates(Node *head) {
    if (head == nullptr)
        return nullptr;

    Node* curr = head;

    while (curr != nullptr) {
        if ((curr->next != nullptr) && curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}


void printDoublyLinkedList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 2 <-> 3 <-> 3 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(2, nullptr, head->next);
    head->next->next->next = new Node(3, nullptr, head->next->next);
    head->next->next->next->next = new Node(3, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(5, nullptr, head->next->next->next->next);

    cout << "Original Doubly Linked List: ";
    printDoublyLinkedList(head);

    
    head = removeDuplicates(head);

    cout << "Doubly Linked List after removing duplicates: ";
    printDoublyLinkedList(head);

    
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
