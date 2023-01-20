class Solution {
public:
    map<int, vector<pair<int, int>>> hash;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto& a: edges){
            hash[a[0]].push_back({a[1], a[2]});
            hash[a[1]].push_back({a[0], a[2]});
        }
        int result = 1e9, ans = -1;
        for(int i = 0; i < n; i++){
            int found = bellman(edges, i, n, distanceThreshold);
            if(found <= result)
                result = found, ans = i;
        }
        return ans;
    }
    int bellman(vector<vector<int>>& edges, int& i, int& n, int& dt){
        vector<int> dist(n, 1e6);
        dist[i] = 0;
        for (int k = 0; k < n; k++) {
            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];
                int duv = e[2];
                
                if (dist[u] > dist[v] + duv) {
                    dist[u] = dist[v] + duv;
                }
                
                if (dist[v] > dist[u] + duv) {
                    dist[v] = dist[u] + duv;
                }
            }
        }
        int count = 0;
        for(int j = 0; j < n; j++)
            count += dist[j] <= dt;
        return count;
    }
};