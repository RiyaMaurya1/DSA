class Solution {
public:
    // brute force
    // time complexity : n log n + O(2n);
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
            if(!ans.empty() && end <= ans.back()[1]){
                continue;
            }
            for(int j = i+1 ; j < n ; j++){
                if(intervals[j][0] <= end){
                    end = max(end , intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};