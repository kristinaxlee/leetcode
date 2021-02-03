/**
 * Validate BST
 * 
 * Solved using a recursive method, where we are performing an in order traversal.
 * In order: from left to right, looks at the bottom of the tree node if thinking about it visually
 *    2
 *   / \
 *  1   3
 * 
 * ex. this tree would be printed like: 1,2,3, which would be ascending order
 * 
 */

class Solution {
public:
  int prev;
  bool firstFound = false;

  bool inOrderTraversal(TreeNode *node) {
      if(node == NULL) {
          return true;
      }
      
      if(!inOrderTraversal(node->left)) {
          return false;
      }
      
      if(firstFound && node->val <= prev) {
          return false;
      }
      
      prev = node->val;
      firstFound = true;
      return inOrderTraversal(node->right);
  }

  bool isValidBST(TreeNode* root) {
      return inOrderTraversal(root);
  }
};