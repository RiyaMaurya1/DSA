class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // rows size
        int n = matrix[0].size(); // columns size
        int row [m];
        int col [n];
        memset(row, 0, sizeof(row));
        memset(col, 0 , sizeof(col));
        
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ;  j < n ; j++ ){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ;  j < n ; j++ ){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
       // time complexity :  O(2*(m x n))
       // space complexity : O(m + n) [this is the space of set we made]
    }
};