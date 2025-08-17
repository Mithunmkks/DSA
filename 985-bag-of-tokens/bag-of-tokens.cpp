class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)return 0;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0])return 0;
        int n = tokens.size();
        int l = 0,h=n-1;
        int ans=0;
        int score=0;
        while(l<=h){
            while(l<n && tokens[l]<=power){
                power-=tokens[l];
                score++;
                ans=max(ans,score);
                l++;
            }
            score--;
            power+=tokens[h];
            h--;
        }
        return ans;
        
    }
};