class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans(2);
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.count(target - nums[i])){
                ans[0] = (mp[target - nums[i]]);
                ans[1] = (i);
                break;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};