class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        reccur(res, temp, candidates, target, 0);
        return res;
    }
    void reccur(vector<vector<int>>& res, vector<int>& arr, vector<int>& nums,
                int s, int i) {
        if (s == 0) {
            res.push_back(arr);
            return;
        }

        if (s < 0 || i == nums.size())
            return;
        arr.push_back(nums[i]);
        reccur(res, arr, nums, s - nums[i], i);
        arr.pop_back();
        reccur(res, arr, nums, s, i + 1);
    }
};