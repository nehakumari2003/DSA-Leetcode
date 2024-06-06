
#include <iostream>
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


Node* DeleteNthNodefromEnd(Node* head, int N) {

    Node* fastp = head;
    Node* slowp = head;

   
    for (int i = 0; i < N; i++)
        fastp = fastp->next;


    if (fastp == NULL)
        return head->next;

  
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}

