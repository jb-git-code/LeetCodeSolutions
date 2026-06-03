class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int low = 1 , high = nums[n-1];
        int result = 0;
        while(low <= high){
            int mid = (high - low)/2 + low;
            if(divSum(nums ,mid) <= threshold){
                result = mid;
                high = mid - 1 ;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }

    int divSum(vector<int> nums ,int num){
        int sumOfResult = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sumOfResult += ceil((double)nums[i] / num);
        }
        return sumOfResult;
    }
};