class Solution {
public:

    void solve(vector<string> &res, int n, int left, int right, string s)
    {
        if(s.size() == 2*n)
        {
            res.push_back(s);
            return;
        }
        if(left < n)
        {
            solve(res, n, left+1, right, s+'(');
        }

        if(right < left)
        {
            solve(res, n, left, right+1, s+')');
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s = "";
        solve(res, n, 0, 0, s);
        return res;
    }
};