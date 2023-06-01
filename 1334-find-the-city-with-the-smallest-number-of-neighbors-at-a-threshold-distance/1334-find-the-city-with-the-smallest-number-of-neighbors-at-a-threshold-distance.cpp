class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<set<int>>neighbor(n);
        
        for(int i = 0 ; i< n ; i++){
            vector <int> dist(n, 1e9);
            dist[i] = 0;
            queue <pair<int,int>>q;
            q.push({0, i});
            while(!q.empty()){
                int dis = q.front().first;
                int node = q.front().second;
                q.pop();
                for(auto it : adj[node]){
                    int d = it.second;
                    int v = it.first;
                    if(dist[v] > dis + d ){
                        dist[v] = dis+d;
                        if(dis+d < distanceThreshold){
                            q.push({dis+d , v});
                            neighbor[i].insert(v);
                        }
                        else if(dis+d == distanceThreshold){
                            neighbor[i].insert(v);
                        }
                    }
                }
            }
        }
        // for(int i = 0 ; i< n ; i++){
        //     cout << "i " << i << " neighbors " << neighbor[i].size() << endl;
        // }
        int mincity = neighbor[0].size();
        for(int i = 0 ; i < n ; i++){
            if(neighbor[i].size() < mincity){
                mincity = neighbor[i].size();
            }
        }
        for(int i = n-1 ; i >= 0 ; i--){
            if(neighbor[i].size() == mincity ){
                return i;
            }
        }
        return 0;
    }
};