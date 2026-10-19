class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        vector<int> tar;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target) tar.push_back(i);
        }
        return tar;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna