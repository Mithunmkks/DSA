class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0),newFreq(26,0),ans;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int st = 0;
        for(int i=0;i<s.size();i++){
            newFreq[s[i]-'a']++;
            freq[s[i]-'a']--;
            bool flag=true;
            for(int j=0;j<26;j++){

                if(newFreq[j]>0 && freq[j]!=0)flag=false;
            }
            if(flag){
                ans.push_back(i+1-st);
                st=i+1;
            }
        }

        return ans;
        

        
    }
};