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
    vector<vector<int>> ans;
    void traverse(TreeNode* root, int targetSum, vector<int>v, int sum){
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(v);
            }
            return;
        }
        if(root->left != NULL){
            int val = root->left->val;
            v.push_back(val);
            traverse(root->left, targetSum, v, sum+val);
            v.pop_back();
        }
        if(root->right != NULL){
            int val = root->right->val;
            v.push_back(val);
            traverse(root->right, targetSum, v, sum+val);
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return {};
        }
        traverse(root, targetSum, {root->val}, root->val);
        return ans;
    }
};
