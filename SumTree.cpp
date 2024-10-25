#include <bits/stdc++.h> 

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

class Solution {
public:

    std::pair<bool, int> isSumTreeHelper(TreeNode<int>* node) {
  
        if (node == NULL) {
            return {true, 0};
        }


        if (node->left == NULL && node->right == NULL) {
            return {true, node->val};
        }


        auto leftResult = isSumTreeHelper(node->left);
        auto rightResult = isSumTreeHelper(node->right);

        bool isLeftSumTree = leftResult.first;
        bool isRightSumTree = rightResult.first;
        int leftSum = leftResult.second;
        int rightSum = rightResult.second;

        bool isCurrentSumTree = (node->val == leftSum + rightSum);

        int totalSum = node->val + leftSum + rightSum;


        return {isLeftSumTree && isRightSumTree && isCurrentSumTree, totalSum};
    }

    bool isSumTree(TreeNode<int>* root) {
        return isSumTreeHelper(root).first;
    }
};
