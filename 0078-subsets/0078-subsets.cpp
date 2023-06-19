class Solution {
public:
    // power set algorithm
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <vector<int>> ans;
        for(int num = 0 ; num < (1<<n) ; num++){
                vector <int> temp;
            for(int bits = 0 ; bits < n ; bits++ ){
                if(num & (1 << bits) ){
                    temp.push_back(nums[bits]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
}; 