class Solution {
public:
    bool dfs(int node , vector<int> &vis , vector<vector<int>> &adjlist)
    {
        vis[node]=1;
        for(auto &adjnode:adjlist[node])
        {
            if(vis[adjnode]==1)return true;
            if(vis[adjnode]==0 && dfs(adjnode,vis,adjlist))return true;
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(n);
        for(auto &p:prerequisites)
        {
            int u = p[0];
            int v = p[1];
            adjlist[u].push_back(v);
        }
        vector<int> vis(n);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 && dfs(i,vis,adjlist))return false; 
        }
        return true;
    }
};