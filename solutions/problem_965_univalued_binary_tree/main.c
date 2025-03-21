#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#include "unity.h"  

// Definition for a binary tree node  
struct TreeNode {  
    int val;  
    struct TreeNode *left;  
    struct TreeNode *right;  
};  

// In-Order traversal to check if all nodes have the same value  
bool in_order(struct TreeNode* node, int value) {  
    if (node == NULL)  
        return true;              
    if (!in_order(node->left, value))  
        return false;   
    if (node->val != value)  
        return false;       
    return in_order(node->right, value);   
}  

// Function to determine if the binary tree is univalued  
bool isUnivalTree(struct TreeNode* root) {  
    if (root == NULL)  
        return true;              
    return in_order(root, root->val);           
}  

// Test function for a univalued tree  
void test_unival_tree_true() {  
    struct TreeNode* root = malloc(sizeof(struct TreeNode));  
    root->val = 1;  
    root->left = malloc(sizeof(struct TreeNode));  
    root->left->val = 1;  
    root->left->left = malloc(sizeof(struct TreeNode));  
    root->left->left->val = 1;  
    root->left->left->left = NULL;  
    root->left->left->right = NULL;  
    root->left->right = NULL;  
    
    root->right = malloc(sizeof(struct TreeNode));  
    root->right->val = 1;  
    root->right->left = NULL;  
    root->right->right = NULL;  

    TEST_ASSERT_TRUE(isUnivalTree(root));  

    // Free allocated memory  
    free(root->left->left);  
    free(root->left);  
    free(root->right);  
    free(root);  
}  

// Test function for a non-univalued tree  
void test_unival_tree_false() {  
    struct TreeNode* root = malloc(sizeof(struct TreeNode));  
    root->val = 1;  
    root->left = malloc(sizeof(struct TreeNode));  
    root->left->val = 1;  
    root->left->left = malloc(sizeof(struct TreeNode));  
    root->left->left->val = 2;  // Different value  
    root->left->left->left = NULL;  
    root->left->left->right = NULL;  
    root->left->right = NULL;  

    root->right = malloc(sizeof(struct TreeNode));  
    root->right->val = 1;  
    root->right->left = NULL;  
    root->right->right = NULL;  

    TEST_ASSERT_FALSE(isUnivalTree(root));  

    // Free allocated memory  
    free(root->left->left);  
    free(root->left);  
    free(root->right);  
    free(root);  
}  

// Main function for running unit tests  
void app_main(void) {  
    UNITY_BEGIN(); // Start Unity testing  

    RUN_TEST(test_unival_tree_true);  
    RUN_TEST(test_unival_tree_false);  

    UNITY_END(); // End Unity testing  
}
