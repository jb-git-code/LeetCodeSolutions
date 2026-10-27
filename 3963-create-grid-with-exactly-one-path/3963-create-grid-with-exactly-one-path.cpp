class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp = "";
        for(int i = 0 ; i < n ; i++) temp += '.';
        ans.push_back(temp);
        for(int i = 1; i < m; i++){
            temp = "";
            for(int j = 0 ; j < n ; j++){
                if(j == n-1) temp += '.';
                else temp += '#';
            }
            ans.push_back(temp);
        }
        return ans;
    }
};