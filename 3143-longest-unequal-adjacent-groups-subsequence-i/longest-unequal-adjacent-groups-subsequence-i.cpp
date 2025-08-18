class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        if(n==1)return words;
        for(int i=0;i<n-1;i++){
            if(groups[i]==groups[i+1]){
                words[i]="A";
            }
        }
        vector<string> ans;
        for(auto s:words){
            if(s!="A")ans.push_back(s);
        }
        return ans;
    }
};