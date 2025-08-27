class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indeg(n+2,0);
        for(auto edge:edges){
            int v = edge[0];
            int u = edge[1];
            indeg[v]++;
            indeg[u]++;
        }
        return max_element(indeg.begin(),indeg.end()) -  indeg.begin() ;

    }
};