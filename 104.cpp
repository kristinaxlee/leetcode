/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxDepth(TreeNode* root) {

        // if node doesn't exist (ex. maxDepth(node->left) == NULL)
        if(root == NULL) {
            return 0;
        }

        // if at leaf node
        else if(root->left == NULL && root->right == NULL) {
            return 1;
        }

        else {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};

// another possible solution is a tree traversal and keep 2 variables holding curDepth + maxDepth
