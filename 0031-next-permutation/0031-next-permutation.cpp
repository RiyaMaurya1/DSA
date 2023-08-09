class Solution {
public:
    // time complexity : O(n);
    // space Complexity : O(1);
 
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return;
        }
        int ind = -1;   // (break point index)
        // 1. find break point aka the dip 
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1] ){
                ind = i;
                break;
            }
        }
        // 2. Find a number that is just greater than the num at the dip ind
        // how we are sure that from traversing from we will get just greater number for sure
        //  and not any other number becz we know that 
        // the nums were increasing from behind before the dip was found.

        if(ind != -1){
            for(int i = n-1 ; i >= 0 ; i--){
                if(nums[i] > nums[ind] ){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1, nums.end());
        }
        else{
            reverse(nums.begin(), nums.end());
        }
        
        return;
    }
};