class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
         // a ^ b = c
        // a = b ^ c
        // c = b ^ a
        int xor1 = 0;
        int xor2 = 0;
        vector <int> ans;
        for(int i = 0 ; i < pref.size() ; i++){
            xor1 = xor2 ^ pref[i];
            ans.push_back(xor1);
            xor2 ^= xor1;
            // xor1 = xor2;
        }
        return ans;
    }
};