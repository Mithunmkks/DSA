class Solution {
public:
    int findLUSlength(string a, string b) {
        int x;
        if(a==b)x=-1;
        else x=max(a.size(),b.size());
        return x;
    }
};