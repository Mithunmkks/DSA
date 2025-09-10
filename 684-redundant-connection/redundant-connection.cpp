class Solution {
public:
    int findParent(int i,vector<int>&parent){
        if(i==parent[i]){
            return i;
        }
        else return parent[i]=findParent(parent[i],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int u_parent = findParent(u,parent);
            int v_parent = findParent(v,parent);
            if(u_parent!=v_parent)parent[u_parent]=v_parent;
            else return edge;
        }
        return {};


    }
};