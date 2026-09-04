class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int minE = INT_MAX;
        int maxE = INT_MIN;
        vector<int> mx(n);
        vector<int> mn(n);

        for(int i = 0 ; i <n ; i++){
            maxE = max(maxE , nums[i]);
            mx[i]= maxE;
        }
        for(int i = n-1 ; i>=0 ; i--){
            minE = min(minE , nums[i]);
            mn[i] = minE;
        }

        for(int i = 0 ; i<n ;i++){
            int curr = mx[i] - mn[i];
            if(curr <= k){
                return i;
            }
        }
        return -1;
    }
};