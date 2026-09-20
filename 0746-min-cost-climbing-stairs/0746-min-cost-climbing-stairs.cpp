class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int one = solve(cost, dp, 0, n);
        int two = solve(cost, dp, 1, n);
        return min(one , two);
    }

    int solve(vector<int>& cost, vector<int>& dp, int i, int n) {
        if (i >= n)
            return 0;
        if(dp[i] != -1) return dp[i];
        int ones = solve(cost, dp, i + 1, n);
        int twos = solve(cost, dp, i + 2, n);
        return dp[i] = cost[i] + min(ones, twos);
    }
};