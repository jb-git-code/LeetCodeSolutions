class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string result = "";
        unordered_map<string,string> mp;
        for(auto it : knowledge){
            string u = it[0];
            string v = it[1];
            mp[u] = v;
        }

        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            //key value case
            if(ch == '('){
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                if(mp.count(temp) == 0) result += '?';
                else result += mp[temp];
            }
            //normal append
            else result += ch;
        }
        return result;
    }
};