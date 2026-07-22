class Solution {
public:
    int countPrimes(int n) {
        //Sieve of Eratosthenes concept is used 
        vector<int> arr(n + 1, 1);
        if(n > 0) arr[0] = 0;
        if(n > 1) arr[1] = 0;
        int i = 2;
        int count = 0;
        while(i <  n){
            if(arr[i] == 1){
                count++;
                int a = 2;
                while(i*a <= n){
                    arr[a*i] = 0;
                    a++;
                }
            }
            i++;
        }
        return count;
    }
};