class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector <int > storexor(n);
        int xor1 = 0;
        int maxvianum = 0;
        for(int i = 0 ; i < n ; i++){
            maxvianum |= nums[i];
            xor1 ^= nums[i];
            storexor[n-1-i] = xor1;
        }
        int reach = 0;
        int givenmax = pow(2, maximumBit);
        if(givenmax > maxvianum){
            reach = givenmax-1;
        }else{
            reach = maxvianum;
        }
        vector <int> ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(storexor[i]^reach);
        }
        return ans;
    }
};