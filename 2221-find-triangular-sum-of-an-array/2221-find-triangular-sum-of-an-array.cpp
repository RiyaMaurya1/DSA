class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector <int> curr = nums;
        int n = curr.size();
        // if(n == 1){
            // return curr[0];
        // }
        
        while(n > 1){
            vector <int> next(n-1);
            for(int i = 0 ; i < n-1 ; i++){
                next[i] = (curr[i]+curr[i+1]) % 10;
            }
            n--;
            curr = next;
        }
        return curr[0];
    }
};