class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> countOfWords;
        for(auto ch:s)countOfWords[ch]++;
        int ans = 0;
        bool singleChar=false;
        for(auto it:countOfWords){
            int freq = it.second;
            if(freq==1)singleChar=true;
            else {
                if(freq%2==0)ans+=freq;
                else {
                    ans+=freq-1;
                    singleChar=true;
                }
            }

            
        }
        if(singleChar)return ans+1;
        else return ans;
        
    }
};