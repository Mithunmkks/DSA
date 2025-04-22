class Solution {
public:
    bool flag = false;
    void solve(int ind,string temp,string &s,int &count,int n,int k,vector<int> &num)
    {
        if(flag)return;


        if(ind==n)
        {
            count++;
            if(count==k){
                s=temp;
                flag = true;
            }
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(!num[i]){
                num[i]=1;
                string  x = to_string(i);
                solve(ind+1,temp+x,s,count,n,k,num);
                
                num[i]=0;
            }


        }
        
    }
    string getPermutation(int n, int k) {
        vector<int> nums(n+1,0);
        int count =0;
        string s="",temp="";
        solve(0,temp,s,count,n,k,nums);
        return s;
    }
};