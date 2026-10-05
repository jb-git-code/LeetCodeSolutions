class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int> arr;
        int score = 0;
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == '(') {
                arr.push_back(score);
                score = 0;
            }
            else{
                if(s[i-1] == '(') {
                    score = arr.back() + 1;
                }
                else{
                    score = (2 * score) + arr.back();
                }
                arr.pop_back();
            }
        }
        // int depth = 0 ;
        // for(int i = 0 ; i < n ; i++){
        //     char c = s[i];
        //     if(c == '(') depth++;
        //     else{
        //         depth--;
        //         if(s[i - 1] == '(') score += (1 << depth);
        //     }
        // }
        return score;
    }
};