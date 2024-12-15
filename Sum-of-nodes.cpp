class Solution {
public:
    int sumNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftNodes = sumNodes(root->left);
        int rightNodes = sumNodes(root->right);

        return leftNodes + rightNodes + 1;
    }
};