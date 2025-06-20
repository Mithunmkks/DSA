class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for(int i=1;i<numRows;i++)
        {
            for(int j=0;j<=i;j++){
                if(j==0)ans[i].push_back(1);
                else if(j==i)ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
        }
        return ans;
        
    }
};

// [1]
// [1,1]
// [1,2,1]
// [1,3,3,1]
// [1,4,6,4,1]