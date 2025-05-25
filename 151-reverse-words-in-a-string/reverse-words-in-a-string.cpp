class Solution {
public:
    string reverseWords(string s) {
        // string ans;
        int n=s.size();

        string temp="";
        vector<string>ans;

        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'){
                temp+=s[i];
            }
            else{
                if(temp.size())
                ans.push_back(temp);
                temp="";
            }
        }
        if(temp.size()) ans.push_back(temp);

        reverse(ans.begin(),ans.end());
        string final;
        for(int i=0;i<ans.size()-1;i++){
            final+=ans[i];
            final+=" ";
        }

        final+=ans[ans.size()-1];

        for(auto &it:ans) cout<<it<<" ";

        cout<<endl;
        return final;
    }
};