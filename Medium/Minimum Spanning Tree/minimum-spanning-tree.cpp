//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    class Disjoint{
        vector <int> size, parent;
        public :
        
            Disjoint(int n){
                size.resize(n+1);
                parent.resize(n+1);
                
                for(int i = 0 ; i < n+1 ; i++){
                    size[i] = 1;
                    parent[i] = i;
                }
                 
            }
            
            int findparent(int x){
                if(x == parent[x]){
                    return x;
                }
                return parent[x] = findparent(parent[x]);
            }
            
            void makeunion(int u, int v){
                int pu = findparent(u);
                int pv = findparent(v);
                
                if(pu == pv) return ;
                
                if(size[pu] < size[pv]){
                    parent[pu] = pv;
                    size[pv] += size[pu];
                }
                else if(size[pu] >= size[pv]){
                    parent[pv] = pu;
                    size[pu] += size[pv];
                }
            }
           
    };
	public:
	//  Using Kruskal's ALgorithm
	
    // 	Time complexity : O(N+E) + O(E logE) + O(E*4α*2)
    //                  make edges, sorting edges, applying finparent and makeunion on all edges;

    //  Space Complexity :  O(N) + O(N) + O(E)
    //                      vector size, vector parent, vector edges. 
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // We need edges and than we will sort them on the basis of wt.
        vector <pair<int,pair<int,int>>> edges;
        for(int i = 0 ; i< V ; i++){
            for(auto it : adj[i]){
                int node = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,v}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum = 0;
        
        Disjoint ds(V);
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findparent(u) != ds.findparent(v)){
                sum += wt;
                ds.makeunion(u,v);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends