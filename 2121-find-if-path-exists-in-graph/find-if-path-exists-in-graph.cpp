class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(auto edge:edges){
            int v = edge[0];
            int u = edge[1];
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            if(node==destination)return true;
            for(auto adjNode:adjList[node]){
                if(!vis[adjNode])q.push(adjNode);
            }
        }
        return false;

    }
};