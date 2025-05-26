class Solution {
public:
    int dp[1001][1001];
    bool solve(int i,int j,string&s)
    {
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]!=s[j])return dp[i][j]=false;
        return dp[i][j]= solve(i+1,j-1,s);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int start = 0;
        int len  = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(i,j,s))
                {
                    if(j-i+1>len)
                    {
                        len=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};