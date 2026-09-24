class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> first;
        vector<int> second;

        for (int i = 0; i < n; i++) {
            if (i != n - 1)
                first.push_back(nums[i]);
            if (i != 0)
                second.push_back(nums[i]);
        }

        return max(solve(first) , solve(second));
    }

    int solve(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        long long int prev1 = arr[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++) {
            long long int inc = arr[i] + prev2;
            long long int exc = 0 + prev1;

            prev2 = prev1;
            prev1 = max(inc, exc);
        }

        return prev1;
    }
};
