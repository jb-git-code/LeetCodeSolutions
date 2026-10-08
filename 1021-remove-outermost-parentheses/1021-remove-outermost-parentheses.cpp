class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int op = 0;
        for( auto c : s){
            if( c == '('){
                if(op > 0) res += c;
                op++; 
            }else{
                op--;
                if(op > 0) res += c;
            }
        }
        return res;
    }
};