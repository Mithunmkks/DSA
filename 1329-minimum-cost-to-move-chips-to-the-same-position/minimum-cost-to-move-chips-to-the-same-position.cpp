class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a=0,b=0;
        for(auto &i:position){
            if(i&1)a+=1;
            else b+=1;
        }
        return min(a,b);
    }
};