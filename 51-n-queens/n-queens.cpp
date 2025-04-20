class Solution {
public:
    int sz;
    bool check(int i,int j,vector<string>&board)
    {
        int row=i,col=j;
        for(;row>=0;row--)
        {
            if(board[row][col]=='Q')return false;
        }
        row=i,col=j;
        for(;(row>=0  && col<sz);row--,col++)
        {
            if(board[row][col]=='Q')return false;
        }
        row =i,col=j;
        for(;(row>=0 && col>=0);row--,col--)
        {
            if(board[row][col]=='Q')return false;
        }
        return true;
    }
    void generateBoards(int ind,vector<string>&board,vector<vector<string>>&ds)
    {
        if(ind==board.size())
        {
            ds.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++)
        {
            if(check(ind,i,board)==true)
            {
                board[ind][i]='Q';
                generateBoards(ind+1,board,ds);
                board[ind][i]='.';
            }

        }


    }
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        sz=n;
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        vector<vector<string>> ds;
        vector<string> board(n,s);
        generateBoards(0,board,ds);
        return ds;
    }
};