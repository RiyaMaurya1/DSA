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
    int ans = 0;
    void traverse(TreeNode* root, long target, long sum){
        if(sum == target){
            ans++;
        }
        if(root->left != NULL){
            int val = root->left->val;
            traverse(root->left, target, sum+val);
        }
        if(root->right != NULL){
            int val = root->right->val;
            traverse(root->right, target, sum+val);
        }
        return;
        
    }
    void call(TreeNode* root, long target){
        if(root != NULL){
            traverse(root, target, root->val);
        }
        if(root->left != NULL){
            call(root->left, target);
        }
        if(root->right != NULL){
            call(root->right, target);
        }
        
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        long target = targetSum;
        call(root, target);
        return ans;
    }
};