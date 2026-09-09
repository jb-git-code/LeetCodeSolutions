class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n < 1000) return ans;
        int digits = 0 ;
        long long temp = n;
        while( temp > 0){
            digits++;
            temp /= 10;
        }
        if (digits <= 6) {
            ans = n - 999;
        } else if (digits <= 9) {
            ans = 999000LL * 1 + (n - 999999LL) * 2;
        } else if (digits <= 12) {
            ans = 999000LL * 1 + 999000000LL * 2 + (n - 999999999LL) * 3;
        } else {
            ans = 999000LL * 1 + 999000000LL * 2 + 999000000000LL * 3 + (n - 999999999999LL) * 4;
            if(digits == 16) ans++;
        }
        return ans;
    }
};