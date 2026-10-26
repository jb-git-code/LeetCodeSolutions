class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited( n , vector<bool>(m , false));
        vector<long long> islands;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    islands.push_back(dfs(grid , visited , i , j));
                }
            }
        }

        int count = 0;
        for(auto it : islands){
            if(it % k == 0) count++;
        }
        return count;
    }


    long long dfs(vector<vector<int>>& grid , vector<vector<bool>>& visited , int i , int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if(grid[i][j] == 0 || visited[i][j]) return 0;
        visited[i][j] = true;

        long long left = dfs(grid , visited , i , j-1);
        long long right = dfs(grid , visited , i , j+1);
        long long top = dfs(grid , visited , i - 1 , j);
        long long bottom = dfs(grid , visited , i + 1 , j);

        return grid[i][j] + left + right + top + bottom;
    }
};