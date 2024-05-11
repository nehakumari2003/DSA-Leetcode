#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* floydDetectLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;

    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}


void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}


void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

  
    head->next->next->next->next = head->next;

    std::cout << "Linked List before removing loop" << std::endl;
    printList(head);

    head = removeLoop(head);

    std::cout << "Linked List after removing loop" << std::endl;
    printList(head);

    return 0;
}
