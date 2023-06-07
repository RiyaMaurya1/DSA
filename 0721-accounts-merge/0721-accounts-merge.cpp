class Solution {
public:
    class Disjoint{
        vector<int> size, parent;
    public:
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0 ; i< n ; i++){
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
        
        void makeunion(int u , int v){
            int ulu = findpar(u);
            int ulv = findpar(v);
            if(ulu == ulv) return;
            
            if(size[ulu] < size[ulv]){
                parent[ulu] = ulv;
                size[ulv] += size[ulu]; 
            }else{
                parent[ulv] = ulu;
                size[ulu] += size[ulv];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n); 
        map <int,string> name;
        map <string,int> mailmap;
        
        for(int i = 0 ; i < n ; i++){
            name[i] = accounts[i][0];
            for(int j = 1 ; j< accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mailmap.find(mail) == mailmap.end()){
                    mailmap[mail] = i; 
                }
                else{
                    int u = mailmap[mail];
                    int v = i;
                    ds.makeunion(u,v);
                }
            }
            
        }
        vector <vector <string>> merged(n);
        for(auto it : mailmap){
            string mail = it.first;
            int node = it.second;
            int ulnode = ds.findpar(node);
            merged[ulnode].push_back(mail);
        }
        // for(auto it : merged){
        //     sort(it.begin(),it.end());
        // }
        
        vector <vector<string>> ans;
         for(int i = 0 ; i< n ; i++){
            if(merged[i].size() > 0){
                vector <string> temp;
                temp.push_back(name[i]);
                sort(merged[i].begin(), merged[i].end());
                for(auto it : merged[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        // for(int i = 0 ; i< n ; i++){
        //     if(merged[i].size() > 0){
        //         merged[i].insert(merged[i].begin(), name[i]);
        //     }
        // }
        return ans; 
    }
};