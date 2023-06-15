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
    // bfs
    vector <int> sum;
    int maxi = INT_MIN;
    void bfs(TreeNode* root){
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int value = 0;
            int size = q.size();
            for(int i = 0 ; i <size ; i++){
                TreeNode* node = q.front();
                value += node->val;
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            // cout << "val " << value << endl;
            maxi = max(maxi, value);
            sum.push_back(value);
        }
    }
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        bfs(root);
        for(int i = 0 ; i < sum.size(); i++){
            if(sum[i] == maxi){
                // cout << "maxi " << sum[i] << " level " << i << endl;
                return i+1;
            }
        }
        return 0;
    }
};