class Solution {
public:
    int n, m;
    int dfs(int row, int col, vector<vector<int>>& vis,
            vector<vector<int>>& heights) {
        if (row == n - 1 && col == m - 1)
            return 0;
        vis[row][col] = 1;
        vector<int> delrow = {1, -1, 0, 0};
        vector<int> delcol = {0, 0, -1, 1};
        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                int effort = abs(heights[row][col] - heights[nr][nc]);
                int nextEffort = dfs(nr, nc, vis, heights);
                effort = max(effort, nextEffort);
                ans = min(ans, effort);
            }
        }
        vis[row][col] = 0;
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        // pair<int,pair<int,int>>
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        dist[0][0]=0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1) {
                return effort;
            }
            vector<int> delrow = {1, -1, 0, 0};
            vector<int> delcol = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m ) {
                    int nextEffort = abs(heights[row][col] - heights[nr][nc]);
                    nextEffort = max(effort, nextEffort);
                    if(nextEffort<dist[nr][nc]){
                        dist[nr][nc]=nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }

};