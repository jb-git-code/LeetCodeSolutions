class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long maxSum = nums[0];
        long winSum = nums[0];
        int n = nums.size();
        for(int i = 1; i<n ;i++){
            winSum = max(winSum + nums[i] ,(long) nums[i]);
            maxSum = max(maxSum , winSum);
        }
        return maxSum;
    }
};