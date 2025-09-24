class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);

        queue<int> q;
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjnode : rooms[node]){
                if(!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push(adjnode);
                }
            }
        }
        int room =  accumulate(vis.begin(),vis.end(),0);
    return room==n;

    }
    
};