class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landEnd = 1e7; // 49
        for(int i=0;i<landStartTime.size();i++){
            landEnd=min(landEnd,landStartTime[i]+landDuration[i]);
        }
        int waterEnd = 1e7;
        int landFinal = 1e7;
        for(int i=0;i<waterStartTime.size();i++){
            waterEnd = min(waterEnd,waterStartTime[i]+waterDuration[i]); 
            if(waterStartTime[i]<=landEnd){ // le = 49 
                landFinal = min(landFinal,landEnd+waterDuration[i]); // 65
            } //     65       //.  65     ,        
            else landFinal = min(landFinal,waterStartTime[i]+waterDuration[i]); //  , 
        }
        int waterFinal = 1e7;
        for(int i=0;i<landStartTime.size();i++){
            if(landStartTime[i]<=waterEnd){
                waterFinal = min(waterFinal,waterEnd+landDuration[i]);
            }
            else waterFinal = min(waterFinal,landStartTime[i]+landDuration[i]);
        }

        return min(landFinal,waterFinal);
        
    }
};