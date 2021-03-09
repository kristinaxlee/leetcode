class Solution {
public:
    int checkHeight(TreeNode *node) {
        if(node == NULL) {
            return -1;
        }
        else {
            return max(checkHeight(node->right), checkHeight(node->left)) + 1;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        return abs(checkHeight(root->left) - checkHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};