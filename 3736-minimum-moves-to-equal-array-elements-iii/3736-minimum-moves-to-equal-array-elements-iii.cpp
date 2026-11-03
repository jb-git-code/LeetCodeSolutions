class Solution {
public:
    int minMoves(vector<int>& nums) {
        int high = INT_MIN;
        for(auto it : nums){
            if(it > high) high = it;
        }
        int moves = 0;
        for(auto it : nums){
            moves += (high - it);
        }
        return moves;
    }
};