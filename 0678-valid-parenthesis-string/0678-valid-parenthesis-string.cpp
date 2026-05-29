class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int minOpenBrackets = 0 , maxOpenBrackets = 0;
        for(int i = 0 ; i< n; i++){
            char ch = s[i];
            if(ch=='(') {
                minOpenBrackets++;
                maxOpenBrackets++;
            }
            else if(ch==')') {
                minOpenBrackets--;
                maxOpenBrackets--;
            }
            else{
                minOpenBrackets--;
                maxOpenBrackets++;
            }
            if(maxOpenBrackets<0) return false;
            minOpenBrackets = max(0,minOpenBrackets);
        }
        return minOpenBrackets == 0;
    }
};