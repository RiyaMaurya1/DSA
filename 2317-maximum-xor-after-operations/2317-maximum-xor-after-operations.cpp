class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = 0 ; j < 32 ; j++){
                if((nums[i] & 1) == 1){
                     ans |= (1<<j);
                }
                nums[i] = nums[i]>>1;
            }
        }
       
        return ans;
        
        // int ans = 0;
        // for(int i = 0 ; i < nums.size(); i++){
        //     ans |= nums[i];
        // }
        // return ans;
    }
};