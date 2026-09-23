class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums,n-1,dp);
    }

    int solve(vector<int> &arr , int n , vector<int> &dp){
        //base con
        if(n == 0) return arr[0];

        if( n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take = arr[n] + solve(arr,n-2 , dp);
        int leave = 0 + solve(arr,n-1 , dp);

        return dp[n] = max(take , leave);
    }
};