class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int rowind = 0;
        int colind = c-1;
        
        while(rowind < r && colind >= 0 ){
            int ele = matrix[rowind][colind];
            
            if(ele == target){
                return 1;
            }
            if(ele < target ){
                rowind++ ;
            }
            else{
                colind-- ;
            }
        }
        return 0;
    }
};