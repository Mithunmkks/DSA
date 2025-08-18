class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int wl = word.size();
        vector<int> dp(n,0);
        int maxi =0;
        for(int i=0;i<n;i++){
            if(word==sequence.substr(i,word.size())){
                int prev = 0;
                if(i-wl>=0)prev=dp[i-wl];
                dp[i]=1+prev;
                maxi=max(maxi,dp[i]);
            }
        }
        return maxi;

        
    }
};