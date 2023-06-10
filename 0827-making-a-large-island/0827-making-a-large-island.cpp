class Solution {
public:
    class Disjoint{
        
    public:
        vector <int> size, parent;
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0 ; i<= n ; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findpar(int x){
            if(x == parent[x]){
                return x;
            }
            return parent [x] = findpar(parent[x]);
        }
        
        void makeunion(int u , int v){
            int ulu = findpar(u);
            int ulv = findpar(v);
            
            if(ulu == ulv) return;
            if(size[ulu] > size[ulv]){
                parent[ulv] = ulu;
                size[ulu] += size[ulv];
            }else{
                parent[ulu] = ulv;
                size[ulv] += size[ulu];
            }
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
//         make union  to build islands
        // I'll store pos of zeros in a array
//         make  visited array for every zero
        // if parent visited then no operation
//         else update temp max island and then finally ans max island;
        
        int n = grid.size();
        Disjoint ds(n*n);
        
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        
        vector <pair<int,int>> zeros;
        for(int i = 0 ; i< n; i++ ){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    for(int k = 0 ; k < 4 ; k++){
                        int nrow = i + row[k];
                        int ncol = j + col[k];
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                            if(grid[nrow][ncol] == 1){
                                int nodepos = i*n + j;
                                int adjpos = nrow*n + ncol;
                                ds.makeunion(nodepos, adjpos);
                            }
                        }
                    }
                }
                else{
                   zeros.push_back({i,j}); 
                }
            }
        }
        if(zeros.empty()){
            return n*n;
        }
        int ans = 0;
        
        for(int i = 0 ; i < zeros.size(); i++){
            int temp = 1;
            int r = zeros[i].first;
            int c = zeros[i].second;
            map<int, int> vis;
            for(int k = 0 ; k < 4 ; k++){
                int nrow = r + row[k];
                int ncol = c + col[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    if(grid[nrow][ncol] == 1){
                        int nodepos = r*n + c;
                        int adjpos = nrow*n + ncol;
                        int up_adjpos = ds.findpar(adjpos);
                        if(!vis[up_adjpos]){
                            vis[up_adjpos] = 1;
                            temp += ds.size[up_adjpos];
                        }
                        
                    }
                }
            }
            ans = max(ans, temp);
            
        }
        return ans;
        
    }
};