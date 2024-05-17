#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

void solve(Node<int>* first, Node<int>* second)
{
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;

    while(next1 != NULL && curr2 != NULL) {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            Node<int>* next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;
        }
    }

    if(curr2 != NULL) {
        curr1->next = curr2;
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first->data <= second->data) {
        solve(first, second);
        return first;
    } else {
        solve(second, first);
        return second;
    }
}