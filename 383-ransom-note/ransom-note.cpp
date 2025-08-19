class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> hashmap;
        for(auto ch:magazine)hashmap[ch]++;
        for(auto ch:ransomNote){
            if(hashmap.find(ch)==hashmap.end())return false;
            else{
                hashmap[ch]--;
                if(hashmap[ch]==0){
                    hashmap.erase(ch);
                }
            } 
        }
        return true;
    }
};