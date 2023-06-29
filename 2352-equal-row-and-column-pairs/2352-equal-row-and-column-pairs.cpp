class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <vector<int>> grid2;
        
        for(int col = 0 ; col < n ; col++){
            vector <int> temp;
            for(int row = 0 ; row < n ; row++){
                temp.push_back(grid[row][col]);
            }
            grid2.push_back(temp);
        }
        int pair = 0;
        for(auto row : grid){
            for(auto col: grid2){
                if(row == col){
                    pair++;
                }
            }
        }
        return pair;
    }
};