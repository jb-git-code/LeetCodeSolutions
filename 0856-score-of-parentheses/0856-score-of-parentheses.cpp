class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        // stack<int> st;
        int score = 0;
        // for (int i = 0; i < n; i++) {
        //     char c = s[i];
        //     if (c == '(') {
        //         st.push(0);
        //     } else {
        //         if (s[i - 1] == '(') {
        //             int temp = st.top();
        //             st.pop();
        //             temp = temp + 1;
        //             st.push(temp);
        //         }
        //         else{
        //             int temp = st.top();
        //             st.pop();
        //             temp = 2 * temp;
        //             st.push(temp);
        //         }
        //     }
        // }
        // while(!st.empty()){
        //     score += st.top();
        //     st.pop();
        // }
        int depth = 0 ;
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == '(') depth++;
            else{
                depth--;
                if(s[i - 1] == '(') score += (1 << depth);
            }
        }
        return score;
    }
};