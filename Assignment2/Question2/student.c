/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, long long min, long long max){
    if (node == NULL) return 0; //base case

    if (node->val <=min || node->val >=max) return -1; //checking bst property
    //checking left and right subtree
    int LeftHeight = checkAVL(node->left, min, node->val);
    if (LeftHeight == -1) return -1;
    int RightHeight = checkAVL(node->right, node->val, max);
    if (RightHeight == -1) return -1;

    if (abs(LeftHeight - RightHeight)>1) return -1;  //height balance check

    if (LeftHeight > RightHeight) return 1 + LeftHeight; //return height
    else return 1 + RightHeight;
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    (void)root;
    int result = checkAVL(root, LLONG_MIN, LLONG_MAX); //bounds
    return result != -1; //turns to true/false statement
}

