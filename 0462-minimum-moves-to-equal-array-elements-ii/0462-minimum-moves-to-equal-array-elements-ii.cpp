class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(begin(nums) , begin(nums) + n/2 , end(nums));
        int x = nums[n/2];
        int moves = 0;
        for(auto it : nums){
            moves += abs(it - x);
        }
        return moves;
    }
};