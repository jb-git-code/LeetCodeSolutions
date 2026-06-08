class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums;
        int j=0;
        for(int i = 1 ; nums.size() < k ; i++){
            if(j < arr.size() && i == arr[j]) {

                j++;

            } else {

                nums.push_back(i);

            }
        }
        return nums[k-1];
    }
};