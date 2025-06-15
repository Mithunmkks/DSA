class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(n);
        vector<int> in(n,0);
        for(auto &p:prerequisites)
        {
            int u = p[0];
            int v = p[1];
            adjlist[v].push_back(u);
            in[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            count++;
            int node = q.front();
            q.pop();
            for(int &adjnode:adjlist[node])
            {
                in[adjnode]--;
                if(in[adjnode]==0)q.push(adjnode);
            }
        }
        return count==n;
    }
};