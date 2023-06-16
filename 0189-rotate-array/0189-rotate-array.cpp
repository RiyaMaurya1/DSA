class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while (k > n){
            k = k%n;
        }
        vector <int> rotated(n);
        for(int i = 0 ; i < n ; i++){
            int ind = (i+k)%n;
            rotated[ind] = nums[i];
        }

        nums = rotated;
    }
};                                                     