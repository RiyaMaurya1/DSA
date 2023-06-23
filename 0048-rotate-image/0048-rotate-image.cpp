class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // lil optimal
    // space cpmplexity  O(1)
        
        int n = matrix.size();
    // transposing the matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    // taking reverse of each row to get the correct answer.
        for(int i = 0 ; i< n ; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        } 
    }
};