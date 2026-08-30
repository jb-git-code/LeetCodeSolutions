class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int low = INT_MAX;
        int high = INT_MIN;
        int ans = 0;
        int minIndex = -1 , maxIndex = -1;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < low){
                low = nums[i];
                minIndex = i;
            }
            if(nums[i] > high){
                high = nums[i];
                maxIndex = i;
            }
        }

        int del1 = 0  , del2 = 0 , del3 = 0;
        if(minIndex < maxIndex) {
            del1 = maxIndex + 1;
            del2 = minIndex + 1 + (n - maxIndex);
            del3 = n - minIndex;
        }else{
            del1 = minIndex + 1;
            del2 = maxIndex + 1 + (n - minIndex);
            del3 = n - maxIndex;
        }

        ans = min(del1 , min(del2 , del3));

        return ans;
    }
};