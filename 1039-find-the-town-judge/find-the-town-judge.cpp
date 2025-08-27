class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1,0),outdeg(n+1,0);
        for(auto edge:trust){
            int u = edge[0];
            int v = edge[1];
            outdeg[u]++;
            indeg[v]++;

        }
        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0)return i;
        }
        return -1;
    }
};