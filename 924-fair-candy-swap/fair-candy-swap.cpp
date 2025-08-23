class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int sumB = accumulate(bobSizes.begin(),bobSizes.end(),0);
        sort(bobSizes.begin(),bobSizes.end());
        for(int i=0;i<aliceSizes.size();i++){
            int x = aliceSizes[i];
            int y = (sumB-sumA)/2 + x;
            int l =0,h=bobSizes.size()-1;
            while(l<=h){
                int mid = l+(h-l)/2;
                if(bobSizes[mid]>y)h=mid-1;
                else if(bobSizes[mid]<y)l=mid+1;
                else return {x,y};
            }

        }
        return {};

    }
};