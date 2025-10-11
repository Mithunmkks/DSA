class Solution {
public:
    string np(string &s){
        string ans = "0";
        for(int i=1;i<s.size()-1;i++){
            if(s[i-1]==s[i+1])ans.push_back('1');
            else ans.push_back('0');
        }
        ans.push_back('0');
        return ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        string base;
        for(int i:cells)base.push_back('0'+i);
        set<string> st;
        bool cycleFound = false;
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt++;
            string nextP = np(base);
            if(st.find(nextP)!=st.end()){
                cycleFound = true;
                break;
            }
            st.insert(nextP);
            base=nextP;
        }
        if(cycleFound){
            int rem = n%(st.size());
            for(int i=0;i<rem;i++){
            string nextP = np(base);
            base=nextP;
            }
        }

        for(int i=0;i<base.size();i++)cells[i]=base[i]-'0';
        return cells ;
    }
};