class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[26] = {0};
        int l = 0, r = 0;
        int n = s.size();
        int totalCount = 0;
        while(r<n) {
            
            //expansion
            while(r < n && !(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)){
                freq[s[r]-'a']++;
                r++;
            }

            //shrinking
            if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                
                while(l<r && (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)){
                    totalCount += (n - r + 1);
                    freq[s[l]-'a']--;
                    l++;
                }

            }

        }
        return totalCount;
    }
};