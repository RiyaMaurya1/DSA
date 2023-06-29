class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[n-1] < 0){
            return ans;
        }
        for(int i = 0 ; i < n ; i++){
            int target = -nums[i];
            int front = i+1;
            int back = n-1;
            
            while(front < back){
                int sum = nums[front]+nums[back];
                
                if(sum < target){
                    front++;
                }
                else if(sum > target){
                    back--;
                }
                else{
                    vector <int> temp;
                    temp = {nums[i], nums[front], nums[back]};
                    
                    while(front < back && nums[front] == temp[1]){
                        front++;
                    }
                    while(front < back && nums[back] == temp[2]){
                        back--;
                    }
                    ans.push_back(temp);
                }
             }
            
            while(i+1 < n && nums[i+1] == nums[i]){
                  i++;  
            }
        }

        return ans;
    }
};