class Solution {
public:
    string removeDigit(string number, char digit) {
        char prev = digit;
        int pos=-1;
        for(int i=0;i<number.size()-1;i++){
            if(number[i]==digit){
                if(number[i+1]>prev){
                    prev=number[i+1];
                    pos=i;
                    break;
                }
            }
        }
        if(pos==-1){
            int n = number.size();
            for(int i=n-1;i>=0;i--){
                if(number[i]==digit){
                    number.erase(i,1);
                    return number;
                }
            }
        }else 
        {
            number.erase(pos,1);
            return number;
        }
        return number;
    }
};