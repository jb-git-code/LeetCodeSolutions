class Solution {
public:
    int minInsertions(string s) {
        int op = 0 ;
        int ans = 0;
        for( int i = 0 ; i < s.size() ; i++){
            char c  = s[i];
            if( c == '(') op++;
            else{
                // opening bracket is present 
                if( op > 0){
                    if(s[i+1] == ')') i += 1;
                    else ans += 1;
                    op--;
                }
                // 0 opening bracket
                else{
                    if(s[i + 1] == ')') {
                        ans += 1;
                        i += 1;
                    }else{
                        ans += 2;
                    }
                }
            }
        }
        return ans + (op * 2);
    }
};