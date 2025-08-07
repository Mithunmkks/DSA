class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if(n==numRows)return s;

        vector<vector<string>> ans(numRows,vector<string>(n+1,""));

        int i=0;
        bool down = true;
        int col = 0;
        while(i<n){
            if(down){
                for(int j=0;j<numRows;j++){
                    if(i<n)ans[j][col]=s[i++];
                }
                col++;
                down=false;
            }
            else{
                for(int j=numRows-2;j>=1;j--){
                    if(i<n)ans[j][col++]=s[i++];
                }
                down=true;
            }
        }
        string zs = "";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n+1;j++){
                zs+=ans[i][j];
            }
        }
        return zs;
    }
};