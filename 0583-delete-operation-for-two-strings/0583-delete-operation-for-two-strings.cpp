class Solution {
public:
    int lcs (string& word1, string& word2, int w1, int w2, vector<vector<int>>& dp){
        if(w1 == 0|| w2 == 0){
            return 0;
        }
        if(dp[w1][w2] > 0){
            return dp[w1][w2];
        }
        
        if(word1[w1-1] == word2[w2-1]){
            dp[w1][w2] = 1 + lcs(word1, word2, w1-1, w2-1, dp);
        }
        else{
            dp[w1][w2] = max(lcs(word1, word2, w1-1, w2, dp), 
                             lcs(word1, word2, w1, w2-1, dp));
        }
        return dp[w1][w2];
    }
    int minDistance(string word1, string word2) {
        
        int w1 = word1.size();
        int w2 = word2.size();
        
        vector <vector<int>> dp(w1+1, vector <int>(w2+1, 0));
        
        int common = lcs(word1, word2, w1, w2, dp);
        return w1+ w2-2*common;
        
    }
};