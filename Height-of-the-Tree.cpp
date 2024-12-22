#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int heightOfBinaryTree(TreeNode* root) {
   
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Height of the binary tree: " << heightOfBinaryTree(root) << endl;

    return 0;
}
