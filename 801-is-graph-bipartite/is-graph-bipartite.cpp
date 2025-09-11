class Solution {
public:
    bool  dfs(int node ,int col , vector<vector<int>> &graph,vector<int> &vis, vector<int> &color){
        vis[node]=1;
        color[node]=col;
        for(int adjnode:graph[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,1-col,graph,vis,color)==false)return false;;
            }
            else {
                if(color[adjnode]==col)return false;
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,-1),vis(n,0);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(!vis[i])ans&=dfs(i,0,graph,vis,colors);
        }
        return ans;

    }
};