class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if((long long)sum > 9LL * num) return "";
        string ans(num,'0');
        for(int i = 0 ; i < num && sum > 0 ; i++){
            int d = min(9,sum);
            ans[i] = '0' + d;
            sum -= d;
        }
        return ans;
    }
};