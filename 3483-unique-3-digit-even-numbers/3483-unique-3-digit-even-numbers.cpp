class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        vector<int> freq(10,0);
        for(auto i : digits){
            freq[i]++;
        }

        for(int i = 100 ; i<= 998 ; i += 2){
            int h = i / 100;
            int t = (i / 10) % 10;
            int o = i % 10;

            vector<int> curr_freq(10 ,0);
            curr_freq[h]++;
            curr_freq[t]++;
            curr_freq[o]++;
            bool possible = true;
            for(int d = 0 ; d < 10 ; d++){
                if(curr_freq[d] > freq[d]){
                    possible = false;
                    break;
                }
            }
            if(possible) count++;
        }

        return count;
    }
    
};