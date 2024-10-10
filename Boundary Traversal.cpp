#include <bits/stdc++.h> 
using namespace std;

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void traverseLeft(TreeNode<int>* root, vector<int> &ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->val);
    
    if(root->left) 
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(TreeNode<int>* root, vector<int> &ans) {
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->val);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode<int>* root, vector<int> &ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    
    ans.push_back(root->val); // Push while backtracking
}

vector<int> boundaryTraversal(TreeNode<int> *root) {
    vector<int> ans;
    
    if(root == NULL)
        return ans;
    
    // Add root node value
    ans.push_back(root->val);
    
    // Traverse the left boundary (excluding leaf nodes)
    traverseLeft(root->left, ans);
    
    // Traverse all the leaf nodes (left subtree first, then right subtree)
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    
    // Traverse the right boundary (excluding leaf nodes), add in reverse
    vector<int> rightBoundary;
    traverseRight(root->right, rightBoundary);
    
    // Append the right boundary to the result in reverse order
    ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());
    
    return ans;
}
