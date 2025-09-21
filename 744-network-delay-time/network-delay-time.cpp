class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        dist[k]=0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times)adj[edge[0]].push_back({edge[1],edge[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cost  = it.first;
            int node = it.second;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int ew = it.second;
                if(cost+ew<dist[adjnode]){
                    dist[adjnode]=cost+ew;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e8)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
};