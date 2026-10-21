class Solution {
public:
    int minOperations(string s) {
        string sorti = s;
        char mn = 'z' , mx = 'a';
        for(auto it : s){
            if(it - 'a' > mx - 'a') mx = it;
            if(it - 'a' < mn - 'a') mn = it;
        }
        int n = s.size();
        bool flag = true;
        for(int i = 1 ; i < n ;i++){
            if(s[i] - 'a' < s[i - 1] - 'a') {
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        else if( n == 2) return -1;
        int ans = 0;
        if(mn == s[0] || mx == s[n-1]) {
            ans = 1;
        }else {
            flag = false;
            for(int i = 1 ; i < n-1 ; i++){
                if(s[i] == mn || s[i] == mx) {
                    flag = true;
                    break;
                }
            }
            if(flag) ans = 2;
            else ans = 3;
        }
        return ans;
    }
};