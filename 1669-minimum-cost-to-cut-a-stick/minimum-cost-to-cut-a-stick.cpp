class Solution {
public:
    int minCostOfCuts(int i, int j, vector<int>& cuts) {
        if (j - i <= 1)
            return 0;
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int leftHalfCost = minCostOfCuts(i, k, cuts);
            int rightHalfCost = minCostOfCuts(k, j, cuts);
            int cost = cuts[j] - cuts[i] + leftHalfCost + rightHalfCost;
            ans = min(ans, cost);
        }
        return ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        n = cuts.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (j - i <= 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int ans = 1e8;
                for (int k = i + 1; k < j; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
};