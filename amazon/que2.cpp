class Solution {
public:
   
    int findCheapestPrice(int n, vector<vector<int>>& flights, int S, int dst, int k) {
        // shortest path algo with a little variation
         vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
         vector<int>dis(n,INT_MAX);
        dis[S]=0;
        queue<pair<int,int>>pq;
        pq.push({0,S});
        int stops=0;
        while(stops<=k and !pq.empty()){
            int sz=pq.size();
            while(sz--){ 
            auto [dist,node]=pq.front();
            pq.pop();
            for(auto& [nb,cost]:adj[node]){
                int temp=cost+dist;
                if(dis[nb]>temp){
                    dis[nb]=temp;
                    pq.push({temp,nb});
                }
            }
            }
            stops++;
        }
      
        return dis[dst]==INT_MAX?-1:dis[dst];
    
    }
};