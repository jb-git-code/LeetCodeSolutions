class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_count = 0 , des_count = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == ((nums[i - 1] + 1) % n)) asc_count++;
            if(nums[i - 1] == ((nums[i] + 1)% n)) des_count++;
        }
        if(asc_count == n-1 && nums[0] == 0) return 0;
        if(asc_count == n-1){
            return min(n - nums[0] , nums.back() + 3);
        }

        if(des_count == n-1){
            return min(n - nums.back() + 1 , (nums[0] + 1) % n +1);
        }

        return -1;
    }
};