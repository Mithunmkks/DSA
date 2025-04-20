class Solution {
public:
    int row,col;
    bool check(int i,int j,char x , vector<vector<char>>& board)
    {
        for(int k=0;k<row;k++)
        {
            if(board[i][k]==x)return false;
            if(board[k][j]==x)return false;
            if(board[3*(i/3) + k/3][3*(j/3) +k%3]==x)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                        char x = '0'+k;
                        if(check(i,j,x,board)==true){
                        board[i][j]=x;
                        if(solve(board)==true)return true;
                        board[i][j]='.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         row = board.size();
         col = board[0].size(); 
        solve(board);
    }
};