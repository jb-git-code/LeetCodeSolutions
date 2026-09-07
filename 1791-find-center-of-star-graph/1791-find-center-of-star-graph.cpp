class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n+2 , 0);

        for(auto i : edges ){
            int u = i[0];
            int v = i[1];

            degree[u]++;
            if(degree[u] > 1) return u;
            degree[v]++;
            if(degree[v] > 1) return v;
        }
        return -1;
    }
};