//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector <int> dist(100000, 1e9);
        queue <pair<int,int>> q;
        int mod = 100000;
        q.push({0, start});
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            for(int i = 0 ; i < arr.size(); i++){
                int n  = (node * arr[i])%mod;
                if(n == end){
                    return steps+1;
                }
                if(dist[n] > steps+1){
                    dist[n] = steps+1;
                    q.push({steps+1, n});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends