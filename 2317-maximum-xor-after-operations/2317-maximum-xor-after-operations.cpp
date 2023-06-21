class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        map <int,int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = 0 ; j < 32 ; j++){
                if(nums[i] & 1 == 1){
                    mp[j]++;
                }
                nums[i] = nums[i]>>1;
            }
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second > 0){
                ans += pow(2, it.first);
            }
            // cout << "bit " << it.first << " no. of bits " << it.second << endl;
        }
        return ans;
    }
};