class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count=0;
        int n=s.size();
        for(auto &ch:s){
            if(ch!='-')count++;
        }
        if(count==0)return "";
        int rem = count%k;
        string ans;
        int i=0;
        if(rem>0){
            while(i<n && rem>0){
                if(s[i]!='-'){
                    rem--;
                    ans.push_back(toupper(s[i]));
                    i++;

                }
                else i++;
            }
            ans.push_back('-');
        }
        int cur = 0;
        while(i<n){
            if(s[i]!='-'){
                cur++;
                ans.push_back(toupper(s[i]));
                if(cur%k==0){
                    ans.push_back('-');
                    cur=0;
                }
                i++;

            }
            else {
                i++;
            }
        }
        ans.pop_back();
        return ans;



        
    }
};