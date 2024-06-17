                                #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

Node* merge(Node* list1, Node* list2){

    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

Node* flattenLinkedList(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {

    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}

                                
                            