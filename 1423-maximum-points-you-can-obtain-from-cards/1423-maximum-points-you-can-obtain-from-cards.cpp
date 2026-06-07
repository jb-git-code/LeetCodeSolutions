class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalSum = 0;
        for (int x : cardPoints) {
            totalSum += x;
        }

        int windowSize = n - k;
        if (windowSize == 0) return totalSum;

        int currWindowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            currWindowSum += cardPoints[i];
        }

        int minWindowSum = currWindowSum;

        for (int i = windowSize; i < n; i++) {
            currWindowSum += cardPoints[i];
            currWindowSum -= cardPoints[i - windowSize];

            minWindowSum = min(minWindowSum, currWindowSum);
        }

        return totalSum - minWindowSum;
    }
};