class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26]={0};
        for(auto ch:magazine)hash[ch-'a']++;
        for(auto ch:ransomNote){
            if(hash[ch-'a']==0)return false;
            hash[ch-'a']--;
        }
        return true;

    }
};