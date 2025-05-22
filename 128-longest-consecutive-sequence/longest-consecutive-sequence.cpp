class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     int n=nums.size();
     if(n==0)return 0;
     int l=0;
     unordered_set<int>st;
     for(int i=0;i<n;i++){
         st.insert(nums[i]);
     }
     for(auto it : st){
         if(st.find(it-1)==st.end()){
             int c=1;
             int v=it;
             while(st.find(v+1)!=st.end()){
                 v=v+1;
                 c+=1;
             }
         l=max(l,c);
         }
     }
     return l;}
};