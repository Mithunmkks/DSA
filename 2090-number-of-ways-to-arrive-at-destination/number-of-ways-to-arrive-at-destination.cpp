class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long > dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long  node = it.second;
            long long  weight = it.first;
            for(auto it:adj[node]){
                long  long  adjnode = it.first;
                long long  edgeWeight = it.second;
                if(weight+edgeWeight<dist[adjnode]){
                    dist[adjnode]=weight+edgeWeight;
                    ways[adjnode]= ways[node];
                    pq.push({dist[adjnode],adjnode});
                }
                else if(weight+edgeWeight==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod;



    }
};