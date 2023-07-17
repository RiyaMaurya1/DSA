//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector <int> vis(26, 0);
		   
		    int n = A.size();
		    string ans = "";
		    queue <char> q;
		    for(int i = 0 ; i < n ; i++){
		        int ch = abs(A[i] - 'a');
		        if(vis[ch] == 0){ // non repeating
		          //  vis[ch] = 1;
		            q.push(A[i]);
		        }
		          //  ans += q.front();
		             
		          //  int ch = abs(A[i] - 'a');
	                bool found = false;
	                vis[ch]++;
	                
	                while(!q.empty()){
	                   
	                    char c = q.front();
	                    
	                    if(vis[(int)(c-'a')] > 1){
	                        q.pop();
	                    }
	                    else{
	                        ans += q.front();
	                        found = true;
	                        break;
	                    }
	                }
	                if(found == false){
	                    ans += '#';
	                }
		            
		        }
		      //  aabcddebj    - a#bbbbbcc 
		      // tcpmxaixsswjelbswxytyhbwjinuhxhvpwaybmdhndafszoghpyzdahiqsgluufqcekjk
		      // tttttttttttttttttttcccccccccccccccccccccccccccccccccccccccccccccppppp
		      // tttttttttttttttttttcccccccccccccccccccccccccccccccccccccccccccccevvvv
		      
		      // queue: t cpmxaiswjelby
		      
		      //  else{
		            
		      //      int ch = abs(A[i] - 'a');
	       //         bool found = false;
	       //         vis[ch]++;
	                
	       //         while(!q.empty()){
	                   
	       //             char c = q.front();
	                    
	       //             if(vis[(int)(c-'a')] > 1){
	       //                 q.pop();
	       //             }
	       //             else{
	       //                 ans += q.front();
	       //                 found = true;
	       //                 break;
	       //             }
	       //         }
	       //         if(found == false){
	       //             ans += '#';
	       //         }
		                
		      //  }
		            
		  //  }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends