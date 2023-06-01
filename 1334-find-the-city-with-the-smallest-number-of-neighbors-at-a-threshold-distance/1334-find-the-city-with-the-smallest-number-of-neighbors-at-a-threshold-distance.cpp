class Solution {
public:
    // using floyd warshal 
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            dist[u][v] = d;
            dist[v][u] = d;
        }
        for(int i = 0 ; i< n ; i++){
            dist[i][i] = 0;
        }
        for(int via = 0 ; via < n ; via ++){
            for(int i = 0 ;  i < n ; i++){
                for(int j = 0 ; j< n ; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        int maxcity = n+1;
        int city = -1;
        for(int i = 0 ; i < n ; i++){ // city
            int count = 0;
            for(int j = 0 ; j < n ; j++){ // adjcity
                if(dist[i][j] <= distanceThreshold){
                    count += 1;
                }
            }
            if(count <= maxcity){
                maxcity = count;
                city = i;
            }
        }
        return city;
    }
};