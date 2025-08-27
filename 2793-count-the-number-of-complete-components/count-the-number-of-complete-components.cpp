class Solution {
public:
    void  dfs(int node,vector<int> &vis,vector<vector<int>> &adjList,int &edges , int &vertices){
        vis[node]=1;
        vertices++;
        for(auto adjNode:adjList[node]){
            edges++;
            if(!vis[adjNode])dfs(adjNode,vis,adjList,edges,vertices);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adjList(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int edges = 0;
                int vertices = 0;
                dfs(i,vis,adjList,edges,vertices);
                if((edges/2)==((vertices*(vertices-1))/2))ans++;
            }
        }
        return ans;
    }
};