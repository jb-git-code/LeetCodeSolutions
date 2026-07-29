class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (compute(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    int compute(vector<int>& nums, int maxx) {
        int cnt = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= maxx) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }
        }

        return cnt;
    }
};