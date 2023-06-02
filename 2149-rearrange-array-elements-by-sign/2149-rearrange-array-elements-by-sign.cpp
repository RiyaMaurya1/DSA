class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s = nums.size();
        vector <int> negs;
        vector <int> post;
        for(int i = 0 ; i < s ; i++){
            if(nums[i] < 0){
                negs.push_back(nums[i]);
            }else{
                post.push_back(nums[i]);
            }
        }
        vector<int> ans;
        int p = 0;
        int n = 0;
        for(int i = 0 ; i < s; i++){
            if(i%2 == 0){
                ans.push_back(post[p]);
                p++;
            }else{
                ans.push_back(negs[n]);
                n++;
            }
        }
        return ans;
    }
};