class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector <string> ans;
        long x = 0;
        // int it = 0;
        for(int i = 0 ; i < n ;){
            x = nums[i];
            string temp = "";
            temp += to_string(nums[i]);
            i++;
            x++;
            bool loop = false;
            while(i < n && i >= 0 && nums[i] == x){
                x ++;
                i ++;
                loop = true;
            }
            if(loop == true){
                temp += "->";
                temp += to_string(nums[i-1]);
            }
            // i = it;
            ans.push_back(temp);
            
        }
        return ans;
    }
};