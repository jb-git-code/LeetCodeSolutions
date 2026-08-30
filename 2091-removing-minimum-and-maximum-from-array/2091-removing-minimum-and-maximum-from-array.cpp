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

        int first = min(minIndex , maxIndex);
        int second = max(minIndex , maxIndex);

        int front = second + 1;
        int back = n - first ;
        int para = first + 1 + (n - second);
        ans = min({front , back , para});
        return ans;
    }
};