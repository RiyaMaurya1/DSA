class Solution {
public:
    // n^2 = for loop and n = maximum while loop running.
    // time complexity : O(n^2 * n )
    // only ans vector is taking space and
    // temp is always of size 4 so taking a constant space of O(1)
    // space complexity : O(no. of quadraples)  
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i+1 ; j < n ; j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    
                    if(sum == target){
                        vector <int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(temp);
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
       return ans; 
    }
};