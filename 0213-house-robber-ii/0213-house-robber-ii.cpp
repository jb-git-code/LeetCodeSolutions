class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> sub1(nums.begin(), nums.begin() + n - 1);
        vector<int> sub2(nums.begin() + 1, nums.end());       

        vector<int> dp1(sub1.size(), -1);
        vector<int> dp2(sub2.size(), -1);

        int ans1 = solve(sub1, sub1.size() - 1, dp1);
        int ans2 = solve(sub2, sub2.size() - 1, dp2);

        return max(ans1, ans2);
    }

    int solve(vector<int>& arr, int n, vector<int>& dp) {
        if (n < 0) return 0;
        if (n == 0) return arr[0];
        if (dp[n] != -1) return dp[n];

        int take = arr[n] + solve(arr, n - 2, dp);
        int leave = 0 + solve(arr, n - 1, dp);

        return dp[n] = max(take, leave);
    }
};