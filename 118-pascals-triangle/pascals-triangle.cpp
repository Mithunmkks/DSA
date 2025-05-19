class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==0)return {};
        if(n==1)return {{1}};

        vector<vector<int>> pr = generate(n-1);
        vector<int> r(n,1);
        for(int i=1;i<n-1;i++)
        {
            r[i]=pr.back()[i-1]+pr.back()[i];
        }
        pr.push_back(r);
        return pr;
    }
};