class Solution {
public:
    // Optimal 
    // time complexity : n log n + O(n);
    // space complexity : O(n) 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector <vector<int>> ans;
        
        int start = 0;
        int end = 0;
        
        for(int i = 0 ; i < n ; i++){
            start = intervals[i][0];
            end = intervals[i][1];
            if(ans.empty() || start > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(end , ans.back()[1]);
            }
        }
        return ans;
    }
};