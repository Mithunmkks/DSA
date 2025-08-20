class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]==toupper(word[i]))count++;
        }
        if(count==n)return true;
        if(count==1 && toupper(word[0])==word[0])return true;
        if(count==0)return true;
        return false;
    }
};