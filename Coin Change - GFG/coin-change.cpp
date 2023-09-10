//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int count(int nums[], int N, int target) {

        // code here.
        
        vector<vector <long long int>>dp(N+1,vector<long long int>(target+1));
      
        //  int n = sizeof(nums)/sizeof(nums[0]);
        // cout << "n " << n << " N " << N << endl;
        for(int i = 0 ; i < N+1 ; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1 ; i < N+1; i++){
            for(int j = 1 ; j < target+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][target];
        
        // return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends