class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor for a Node with both data and a reference to the next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for a Node with data and no reference to the next node (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


