class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minIndexLen(n,INT_MAX);
        int start = 0, end = 0;
        int currSum = 0;
        int bestMin = INT_MAX;
        int minLen = INT_MAX;
        bool flag = false;
        while (end < n) {
            currSum += arr[end];
            if (currSum > target) {
                while (start <= end && currSum > target) {
                    currSum -= arr[start];
                    start++;
                }
            }
            if (currSum == target) {
               int len = end - start + 1;
               if( start > 0  && minIndexLen[start-1] != INT_MAX){
                    minLen = min(minLen , len + minIndexLen[start-1]);
                    flag = true;
               }
               bestMin = min(bestMin , len);
            }
            
            minIndexLen[end] = bestMin;
            end++;
        }

        return flag ? minLen : -1;
    }
};