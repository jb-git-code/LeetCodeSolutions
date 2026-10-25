class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m , false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                   if(dfs(grid , visited ,i , j)) count++;
                }
            }
        }
        return count;
    }

    bool dfs(vector<vector<int>>& grid ,vector<vector<bool>>& visited , int i , int j){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return false;
        if(visited[i][j]) return true;
        if(grid[i][j] == 1) return true;
        visited[i][j] = true;
        bool left = dfs(grid , visited ,i , j-1);
        bool right = dfs(grid ,visited ,  i , j+1);
        bool top = dfs(grid , visited ,i-1 , j);
        bool bottom = dfs(grid , visited ,i+1 , j);

        return (left && right && top && bottom);
    }
};