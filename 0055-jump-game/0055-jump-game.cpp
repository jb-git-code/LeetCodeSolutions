class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJumpIndex = 0;
        for(int i = 0 ;i<n-1 ;i++){
            if(nums[i]!=0){
               maxJumpIndex = max(maxJumpIndex,nums[i] + i);
            }
            else{
                if(maxJumpIndex <=  i) return false;
            }
        }
        return maxJumpIndex >= (n-1);
    }
};