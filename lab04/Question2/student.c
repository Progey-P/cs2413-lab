#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool mirror (struct TreeNode* left, struct TreeNode* right){
  if (left == NULL && right == NULL) return true; //if same
  if ((left == NULL && right != NULL) || (right == NULL && left != NULL)){ //if one longer
    return false;
  }
  if (left->val != right->val) return false; //if val not the same
  return mirror (left->left, right->right) &&
    mirror (left->right, right->left);
}



bool isSymmetric(struct TreeNode* root) {
  // TODO: implement
  if (root == NULL) return true;
  return mirror (root->left, root->right);
}