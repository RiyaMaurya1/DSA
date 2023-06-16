class Solution {
public:
    
    // in a sorted rotated array there is only one pair which has nums[i-1] > nums[i];
    bool check(vector<int>& nums) {
        int cnt = 0 ;
        int n = nums.size();
        
        for(int i = 1 ; i < n ; i++ ){
            if(nums[i-1] > nums[i]){
                cnt ++;
            }
        }
        if(nums[n-1] > nums[0]){
            cnt++;
        }
        if(cnt == 0){
            return true;
        }
        return cnt==1;
    }
};