class Solution {
public:
    int longestValidParentheses(string s) {
        int op = 0 , cl = 0;
        int ans = 0;
        for(auto c : s){
            if(c == ')'){
                if(cl + 1 > op) {
                    op = 0;
                    cl = 0;
                }
                else {
                    cl++;
                    if( op == cl) ans = max(ans , op + cl); 
                }
            }
            else op++;
        }
        op = 0 ; cl = 0;
        int temp = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if(s[i] == ')') cl++;
            else{
                if( op + 1 > cl ){
                    op = 0 ; 
                    cl = 0;
                }
                else {
                    op++;
                    if(op == cl) temp = max(temp , op + cl);
                }
                
            }
        }
        return max(ans, temp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna