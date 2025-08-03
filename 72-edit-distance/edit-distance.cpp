class Solution {
public:
    int dp[501][501];
    int minEdit(int i,int j,string &word1 ,string &word2){
        if(i>=word1.size()){
            return word2.size()-j;
        }
        else if(j>=word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]) return minEdit(i+1,j+1,word1,word2);

        int replaceChar  = 1 + minEdit(i+1,j+1,word1,word2);
        int deleteChar = 1 + minEdit(i,j+1,word1,word2);
        int insertChar = 1 + minEdit(i+1,j,word1,word2);
        return dp[i][j] = min({replaceChar,deleteChar,insertChar});
    }
    int minDistance(string word1, string word2) {
        if(word1.size()==0)return word2.size();
        if(word2.size()==0)return word1.size();
        memset(dp,-1,sizeof(dp));
        return minEdit(0,0,word2,word1);
    }
};