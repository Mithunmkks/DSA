class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a ,b;
        for(int i=0;i<m;i++)a.push_back(nums1[i]);
        for(int i=0;i<n;i++)b.push_back(nums2[i]);
        int i=m-1;
        int j=0;
        while(i>=0 && j<n)
        {
            if(a[i]>=b[j]){
            swap(a[i],b[j]);
            i--;
            j++;
            }
            else 
            {
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<m;i++)
        {
            nums1[i]=a[i];
        }
        for(int i=0;i<n;i++)
        {
            nums1[i+m]=b[i];
        }
    }
};

