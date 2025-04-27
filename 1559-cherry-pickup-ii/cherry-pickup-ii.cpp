class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if(i==j){
                    dp[i][j]=grid[n-1][i];
                    continue;
                }
                dp[i][j]=grid[n-1][i]+grid[n-1][j];
            }
        }
        for (int i = n-2; i>=0; i--) {
            vector<vector<int>> temp(m, vector<int>(m, 0));
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int value;
                    if (j1 == j2)
                        value = grid[i][j1];
                    else
                        value = grid[i][j1] + grid[i][j2];
                    int ans = -1e8;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if(j1+x>=0 && j1+x<m && j2+y>=0 && j2+y<m)
                            ans = max(ans, dp[j1+x][j2+y]+value);
                        }
                    }
                    temp[j1][j2]=ans;
                }
            }
            dp=temp;
        }
        return dp[0][m-1];
    }
};