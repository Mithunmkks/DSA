class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto i:answers)mp[i]++;
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans+=it.first+1;
                continue;
            }
            else
            {
                if(it.second<(it.first+1))
                {
                    ans+=it.first+1;
                    continue;
                }
                else if(it.second%(it.first+1)==0)
                {
                    ans+=(it.second/(it.first+1))*(it.first+1);
                
                }
                else
                {
                    ans+=(it.second/(it.first+1)+1)*(it.first+1);
                }
            }
        }
        return ans;
    }
};