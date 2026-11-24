class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxlen = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            long long gcdR = nums[i];
            long long lcmR = nums[i];
            long long pro  = nums[i];
            for(int j = i+1 ; j < n ;j++){
                gcdR = gcd(gcdR , nums[j]);
                lcmR = lcm(lcmR , nums[j]);
                if(pro > 1000000) break;
                pro *= nums[j];
                if(pro == (gcdR * lcmR)) {
                    maxlen = max(maxlen , j-i+1);
                }
            }
        }
        return maxlen;
    }

    long long lcm(long long a , long long b){
        if(a == 0 || b == 0) return 0;
        long long lcm = abs((a / gcd(a , b)) * b);
        return lcm;
    }

    long long gcd (int a , int b){
        if(a == 0 || b == 0) return 0;
        while(b != 0){
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a);
    } 
};