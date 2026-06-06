class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        int arr1[26];
        int arr2[26];
        for(int i = 0 ; i < n ;i++){
            char ch = s[i];
            arr1[ch-'a']++;
        }
        for(int i = 0 ; i < n ;i++){
            char ch = t[i];
            arr2[ch-'a']++;
        }
        for(int i = 0 ; i < 26;i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
};