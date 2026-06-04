class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0 , high = 0;
        int result = 0;
        for( int i = 0 ; i < n; i++){
            low = max(low , weights[i]);
            high += weights[i];
        }

        while(low <= high){
            int mid = (high - low )/2 + low;
            if(isPack(weights , mid ) <= days){
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }
    int isPack(vector<int>& arr, int cap) {
        int days = 1;
        int load = 0;

        for(int w : arr) {
            if(load + w > cap) {
                days++;
                load = w;
            }
            else {
                load += w;
            }
        }

        return days;
    }
};