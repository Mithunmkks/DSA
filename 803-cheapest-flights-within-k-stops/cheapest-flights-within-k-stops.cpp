class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
               vector<vector<pair<int,int>>> adj(n);


        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e8);
        dist[src]=0;
        queue<array<int,3>> q;
        q.push({0,src,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it[0];
            int node = it[1];
            int cost = it[2];
            if(stops>k)continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int ew = it.second;
                if(ew+cost<dist[adjnode]){
                    dist[adjnode]=ew+cost;
                    q.push({stops+1,adjnode,dist[adjnode]});
                }
            }
            
        }
        if(dist[dst]==1e8)return -1;
        else return dist[dst];


    }
};