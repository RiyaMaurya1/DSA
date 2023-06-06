class Solution {
public:
    class DisjointSet{
    public:
        vector <int> parent;
        DisjointSet(int n){
            parent.resize(n+1);
            for(int i = 0 ; i< n ; i++){
                parent[i] = i;
            }
        }
        
        int findpar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findpar(parent[node]);
        }
        
        void makeunion(int u, int v){
            int pu = findpar(u);
            int pv = findpar(v);
            
            if(pu == pv) return ;
            parent[pu] = pv;
        }
        
    
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        // count extra edges 
        // count components.
        DisjointSet ds(n);
        int extraedge = 0 ;
        int components = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            if(ds.findpar(u) != ds.findpar(v)){
                ds.makeunion(u,v); 
            }
             else{
                extraedge++;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i] == i){
                components++;
            }
        }
        if(extraedge >= components-1){
            return components-1;
        }
        return -1;
    }
    
};