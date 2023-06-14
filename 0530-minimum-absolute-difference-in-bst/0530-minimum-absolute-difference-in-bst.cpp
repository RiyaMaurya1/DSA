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

//  Inorder traversal in BST is sorted.
    int getmin = INT_MAX;
    TreeNode *prev = NULL;
    void traversal(TreeNode* root){
        int diff = 0;
        if(root->left != NULL){
            traversal(root->left);
        }
        if(prev != NULL){
            // root->val will always be greater than prev->val as we going in sorted fashion.
            diff = ( root->val - prev->val);
            getmin = min(diff, getmin);
        }
        prev = root;
        if(root->right != NULL){
            traversal(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return getmin;
    }
};