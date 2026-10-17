class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortt(nums);
        auto lamda = [&](int a , int b){
            int digOne = sumDigits(a);
            int digTwo = sumDigits(b);
            if(digOne != digTwo) return digOne < digTwo;
            else return a < b;
        };
        sort(sortt.begin() , sortt.end()  ,lamda);
        unordered_map<int , int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i;
        }
        int swaps = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int exp = sortt[i];
            if(curr != exp){
                int evi = mp[exp];
                nums[i] = exp;
                nums[evi] = curr;
                mp[curr] = evi;
                mp[exp] = i;
                swaps++;
            }
        }
        return swaps;
    }


    int sumDigits(int n){
        int sum = 0 ;
        while(n > 0){
            sum += (n%10);
            n = n/10;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna