class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=matrix[j][i];
            }
        }
        matrix=dp;
        for(auto &i:matrix)reverse(i.begin(),i.end());
    }
};