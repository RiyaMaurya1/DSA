class Solution {
    class Disjoint{
          public: 
            vector<int> size, parent;
            Disjoint(int n){
                parent.resize(n+1);
                size.resize(n+1);
                for(int i = 0 ; i <= n ; i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }
        
        int findpar(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = findpar(parent[x]);
        }
        
        void makeunion (int u, int v){
            int ulu = findpar(u);
            int ulv = findpar(v);
            if(ulu == ulv ) return ;
            
            if(size[ulu] < size[ulv]){
                parent[ulu] = ulv;
                size[ulv] += size[ulu];
            }else{
                parent[ulv] = ulu;
                size[ulu] += size[ulv];
            }
            
        }        
    };
public:
    
    int removeStones(vector<vector<int>>& stones) {
//         all the stones in same row or same col will make one component.
//         we can delete all stones from a component except one as there will be no other stone
//         in the same row or col.
//         so the maximum stones that we can remove is total stones - no. of components.
            int n = stones.size();
            int maxrow = 0;
            int maxcol = 0;
            for(auto it : stones){
                maxrow = max(maxrow , it[0]);
                maxcol = max(maxcol , it[1]);
            }
            
            Disjoint ds(maxrow +maxcol +1);
            unordered_map <int,int> stoneNodes;
            for(auto it : stones){
                int row = it[0];
                int col = it[1]+ maxrow +1;
                ds.makeunion(row, col);
                stoneNodes[row] = 1;
                stoneNodes[col] = 1;
            }
        
            int components = 0;
            for(auto i: stoneNodes){
                if(ds.findpar(i.first) == i.first){
                    components++;
                }
            }
        return n-components;
    }
};