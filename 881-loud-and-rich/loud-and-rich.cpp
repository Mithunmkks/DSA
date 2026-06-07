class Solution {
public:
// <quietness,sourcenode> 
    pair<int,int> dfs(int node,vector<int>&vis,vector<int>&quiet,vector<vector<int>>&adj,vector<int>&ans){
      // vis[node]=1;
        if(ans[node]!=node)return {quiet[ans[node]],ans[node]};
        int quietness = quiet[node];
        int sourcenode=node;
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                pair<int,int> pp = dfs(adjnode,vis,quiet,adj,ans);
                if(pp.first<quietness){
                    quietness=pp.first;
                    sourcenode=pp.second;
                }
            }
        }
        ans[node]=sourcenode;
        return {quietness,sourcenode};
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        vector<vector<int>> adj(n);
        for(auto it:richer){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,vis,quiet,adj,ans);
        }
        return ans;
    }
};