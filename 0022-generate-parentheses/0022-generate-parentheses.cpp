class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res , n , n , "");
        return res;
    }

    void solve(vector<string> &arr , int s , int e , string str){
        if(s > e) return;
        if(s == 0 && e == 0){
            arr.push_back(str);
            return;
        }
        if(s > 0) solve(arr,s-1,e,str+'(');
        if( e > 0) solve(arr,s ,e-1,str + ')');
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna