class Solution {
public:
    bool isPalindrome(int i, int j, string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;

    }
    void solve(int ind,string s,vector<string> & temp,vector<vector<string>> &ds)
    {
        if(ind==s.size()){
            ds.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalindrome(ind,i,s))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp,ds);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ds;
        vector<string> temp;
        solve(0,s,temp,ds);
        return ds;
    }
};