class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bits(32, 0);

        for (int b = 0; b < 32; b++) {
            for (int x : nums) {
                if (x & (1 << b))
                    bits[b]++;
            }
        }

        long long res = 0;
        while (k--) {
            long long curr = 0;
            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    bits[b]--;
                    curr |= (1LL << b);
                }
            }
            res = (res + (curr % MOD) * (curr % MOD)) % MOD;
        }
        return (int)res;
    }
};