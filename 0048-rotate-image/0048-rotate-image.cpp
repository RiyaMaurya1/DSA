class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    //  Brute Force Approach is taking elements and put it into other matrix 
        int n = matrix.size();
        vector <vector<int>> ans(n, vector<int>(n,0));
        // matrix[i][j] = ans[j][n-1-i]
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};