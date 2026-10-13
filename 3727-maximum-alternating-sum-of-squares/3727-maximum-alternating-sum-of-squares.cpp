class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nums[i] = nums[i] * nums[i];
        }
        nth_element(nums.begin() , nums.begin() + n/2 , nums.end());
        long long sum = 0  , diff = 0;
        for(int i = 0 ; i < n/2 ; i++){
            diff += (long long)(nums[i]);
        }
        for(int i = n/2 ; i < n ; i++){
            sum += (long long)(nums[i]);
        }
        return sum - diff;
    }
};
