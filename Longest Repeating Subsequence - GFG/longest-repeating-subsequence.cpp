//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string str1 = str;
		    int n = str1.size();
		    
		    int dp[n+1][n+1];
		  //  dp[n][string of size n];
		    
		    for(int i = 0 ; i< n+1 ; i++){
		        dp[0][i] = 0;
		        dp[i][0] = 0;
		        
		    }
		    for(int i = 1 ; i < n+1 ; i++){
		        for(int j = 1 ; j < n+1 ; j++){
		            if(i != j && str[i-1] == str1[j-1]){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends