class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map <vector<int>, int> mp;
        
        for(auto it : grid){
            mp[it]++;
        }
        int pair = 0;
        for(int col = 0 ; col < n ; col++){
            vector <int> temp;
            for(int row = 0 ; row < n ; row++){
                temp.push_back(grid[row][col]);
            }
            pair += mp[temp];
        }
      
        return pair;
    }
};