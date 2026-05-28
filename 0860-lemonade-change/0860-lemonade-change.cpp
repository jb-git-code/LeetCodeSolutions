class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0 , tens = 0 ;
        for(int i = 0 ; i<n ;i++){
            if(bills[i]==5) fives++;
            else if(bills[i] == 10){
                if(fives==0) return false;
                else {
                    fives--;
                    tens++;
                }
            }
            else{
                if((fives>0 && tens>0)) {
                    fives--;
                    tens--;
                }
                else if(fives>=3 && tens==0){
                    fives-=3;
                }
                else return false;
            }
        }
        return true;
    }
};