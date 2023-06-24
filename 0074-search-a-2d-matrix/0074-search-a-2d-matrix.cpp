class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int start = 0 ; 
        int end = r*c - 1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            int ele = matrix[mid/c][mid%c];
            
            if( ele == target){
                return true;
            }
            if(ele < target){
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};