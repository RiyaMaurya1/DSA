class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map <int, int> freq;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }
        
        int ans = 0;
        map <int, int> used;
        for(int i = 0 ; i < n ; i++){
            int num = nums[i];
            int partner = k-num;
            if(used[num] == 0 && used[partner] == 0){
                if(num == partner){
                    int half = freq[num];
                    ans += half/2;
                }
                else{
                    ans += min(freq[num], freq[partner]);
                }
                used[num] = 1;
                used[partner] = 1;
            }
        }
        return ans;
    }
};