class Solution {
public:
    string maximumTime(string time) {
        if(time[0]=='?'){
            if(time[1]=='?' || time[1]<'4')time[0]='2';
            else time[0]='1';
        }
        if(time[1]=='?'){
            if(time[0]=='0' || time[0]=='1')time[1]='9';
            else time[1]='3';
        }
        if(time[3]=='?')time[3]='5';
        if(time[4]=='?')time[4]='9';
        return time;
    }
};



// pos = 1 
// all val = 0,1,2 
//          0-> never
//          1-> when pos2 have {>3}
//          2 -> when pos2 have {1,2,3};
// pos = 2 
// all val = 0,1,2,3,4,5,6,7,8,9
//           when pos1 have 0 => can put all values , will take max => 9 
//           when pos1 have 1 => can put all values , will take max => 9 
//           when pos1 have 2 => can have 1,2,3 => will take make => 3 
// :
// pos = 3 
//  all val = > 1,2,3,4,5
//  will take max = 5 
//  pos = 4 
//  all val =>  1-9 => max=> 9 