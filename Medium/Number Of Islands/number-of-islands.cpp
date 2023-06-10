//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    class Disjoint{
        vector <int> size, parent;
    public:
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findpar (int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = findpar(parent[x]);
        }
            
        void makeunion(int u, int v){
            int ulu = findpar(u);
            int ulv = findpar(v);
            
            if(ulu == ulv) return ;
            if(size[ulu] > size[ulv]){
                parent[ulv] = ulu;
                size[ulu] += size[ulv];
            }
            else{
                size[ulv] += size[ulu];
                parent[ulv] = ulu;
            }
        }
    };
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        Disjoint ds(n*m);
        int vis[n][m];
        memset(vis, 0 , sizeof(vis));
        int cnt = 0;
        vector <int> ans;
        
        for(auto it: operators){
            int r = it[0];
            int c = it[1];
            
            if(vis[r][c] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[r][c] = 1;
            cnt++;
            
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ){
                    if(vis[nrow][ncol] == 1){
                        int pos = r*m + c;
                        int adjpos = nrow*m + ncol;
                        
                        if(ds.findpar(pos) != ds.findpar(adjpos)){
                            cnt--;
                            ds.makeunion (pos, adjpos);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends