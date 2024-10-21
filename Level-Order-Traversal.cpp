#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build the tree
Node* buildTree(Node* root){
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    if(data == -1){
        return NULL; // Leaf node
    }

    root = new Node(data); // Create a new node with the entered data

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);  // Recursively build the left subtree

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right); // Recursively build the right subtree

    return root;  // Return the current node
}

// Function to perform level-order traversal
void levelOrderTraversal(Node* root){
    if(root == NULL){
        return; // If the tree is empty, return
    }

    queue<Node*> q; // Create a queue to store nodes
    q.push(root);   // Push the root node
    q.push(NULL);   // Marker for the end of a level

    while(!q.empty()){
        Node* temp = q.front(); // Get the front node
        q.pop(); // Remove it from the queue

        if(temp == NULL){
            // End of a level
            cout << endl;

            if(!q.empty()){ // If more nodes are remaining, add the level marker
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " "; // Print the data of the node

            // Push the left child if it exists
            if(temp->left){
                q.push(temp->left);
            }

            // Push the right child if it exists
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root); // Build the tree

    cout << "Level Order Traversal of the Tree:" << endl;
    levelOrderTraversal(root); // Perform level-order traversal

    return 0;
}
