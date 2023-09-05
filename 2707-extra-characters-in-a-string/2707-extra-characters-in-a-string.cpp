class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, vector<int>&dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index]; //use the stored results
        
        string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            //currStr will be a string from (index to cutIdx)
            
            //if string not in dictionary, we have to delete as they are extra chars
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, dp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int>dp(s.size(), -1);
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, dp, 0);
        return ans;
        
    }
};

// class Solution {
// public:
//     unordered_set<string> st;
//     vector<int> mem;

//     int solve(string& s, int ind){ 
//         if(ind >= s.size()) return 0;
//         if(mem[ind] != -1) return mem[ind];
//         int res = 1 + solve(s, ind + 1);   //skip one element with vlaue 1 added to result
//         for(int i = 1; ind + i <= s.size(); ++i){ //check if any of the chars can be skiped without any value returned 
//             string t = s.substr(ind, i);
//             if(st.find(t) != st.end()) res = min(res, solve(s, ind+i));
//         }
//         return mem[ind] = res;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         mem.resize(s.size() + 1, -1);
//         for(auto d: dictionary ) st.insert(d);
//         return solve(s, 0);
//     }
// };