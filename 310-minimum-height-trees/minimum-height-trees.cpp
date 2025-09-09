class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto e:edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1)q.push(i);
        }
        int nodeLeft = n;
        while(nodeLeft>2){
            int k = q.size();
            for(int i=0;i<k;i++){
            int node = q.front();
            q.pop();
            nodeLeft--;
            for(auto adjnode:adj[node]){
                indeg[adjnode]--;
                if(indeg[adjnode]==1){
                    q.push(adjnode);
                   
                }
            }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        if(ans.size()!=0)return ans;
        else return {0};

    }
};