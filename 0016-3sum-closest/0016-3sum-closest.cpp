class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mindiff = INT_MAX;
        int closest = 0;
        int absdiff = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++){
            int left = i+1;
            int right = n-1;
            
            while(left < right){
                int sum = nums[i] + nums[left] +nums[right];
                
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
                
                absdiff = abs(sum - target);
                // cout << "sum: " << sum << " abs diff: " << absdiff << endl;
                if(absdiff < mindiff){
                    closest = sum;
                    mindiff = absdiff;
                }
                
            }
        }
        return closest;
    }
};