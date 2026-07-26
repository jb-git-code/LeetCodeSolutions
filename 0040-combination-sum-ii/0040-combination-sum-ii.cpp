class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>>  res ;
        vector<int> curr;
        solve(res,candidates,curr,target,0);
        return res;
    }
    void solve(vector<vector<int>>& res,
           vector<int>& candidates,
           vector<int>& curr,
           int target,
           int index) {

        if (target == 0) {
            res.push_back(curr);
            return;
        }   
        
        for(int i = index ; i < candidates.size(); i++){
            if( i > index && candidates[i] == candidates[i-1]) continue;

            if( candidates[i] > target) break;

            curr.push_back(candidates[i]);

            solve( res,candidates , curr , target - candidates[i] , i + 1);

            curr.pop_back();
        }
    
    }
};