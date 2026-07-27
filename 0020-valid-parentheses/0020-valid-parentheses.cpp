class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> para;
        int i = 0;
        while(i<n){
            char ch = s[i];
            if(ch == '[' || ch == '{' || ch == '('){
                para.push(ch);
            }
            else{
                if(para.empty()) return false;
                else if((ch == ']' && (para.top() == '[')) || (ch == ')' && (para.top() == '(')) || (ch == '}' && (para.top() == '{'))) para.pop();
                else para.push(ch); 
            }
            i++;
        }
        return para.empty();
    }
};