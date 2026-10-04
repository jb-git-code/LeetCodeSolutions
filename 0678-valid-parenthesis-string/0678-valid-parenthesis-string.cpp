class Solution {
public:
    bool checkValidString(string s) {
        stack<char> star ,op;
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if(c == '(' ) op.push(i) ;
            else if( c == '*') star.push(i);
            else{
                if(!op.empty()) op.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!star.empty() && !op.empty()){
            if(op.top() > star.top()) return false;
            op.pop();
            star.pop();
        }
        return op.empty();
    }
};