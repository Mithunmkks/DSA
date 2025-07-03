class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k)
        {
            int x = s.size();
            for(int i=0;i<x;i++)
            {
                s.push_back('a'+(((s[i]-'a')+1)%25));
            }
        }
        return s[k-1];
    }
};