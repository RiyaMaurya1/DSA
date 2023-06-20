class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(int i = 0 ; i < encoded.size() ; i++){
            int d = ans[i]^encoded[i];
            ans.push_back(d);
        }
        return ans;
    }
};