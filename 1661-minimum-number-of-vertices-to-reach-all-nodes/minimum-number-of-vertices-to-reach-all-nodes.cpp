class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<int> &vis){
        vis[node]=1;
        for(auto &adjnode:graph[node]){
            dfs(adjnode,graph,vis);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0),vis(n,0);
        vector<vector<int>> adjList(n);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            indeg[v]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)ans.push_back(i);
        }

        return ans;
    }
};