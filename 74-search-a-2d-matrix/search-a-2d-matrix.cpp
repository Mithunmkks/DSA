class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix.size()-1;
       
        while(l<=h)
        {
           int  mid = (l+h)/2;
            if(matrix[mid][0]>target)h=mid-1;
            else l=mid+1;
        }

        if (h < 0) return false;
        int row = h;
        l=0,h=matrix[0].size()-1;
        while(l<=h)
        {
           int  mid=(l+h)/2;
            if(matrix[row][mid]==target)return true;
            if(matrix[row][mid]<target)l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};