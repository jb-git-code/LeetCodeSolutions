class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(101,0);
        for(int i = 0 ; i < nums.size() ; i++){
            int count = 0;
            for(int j = i ; j < nums.size(); j++){
                if(freq[nums[j]] == 0) {
                    count++;
                    freq[nums[j]]++;
                    
                }
                ans = ans + (count * count);
            }
            fill(freq.begin() , freq.end() , 0);
        }
        return ans;
    }
};