class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> onesA;
        vector<pair<int,int>> onesB;
        int n = img1.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                if(img1[i][j] == 1) onesA.push_back(make_pair(i,j));
                if(img2[i][j] == 1) onesB.push_back(make_pair(i,j));
            }
        }
        int maxOverlap = 0;
        unordered_map<int,int> shiftCount;
        for(auto a : onesA){
            for(auto b : onesB){
                int dx = b.first - a.first;
                int dy = b.second - a.second;
                int key = (dx * n)*2*n + (dy * n);
                maxOverlap = max(maxOverlap , ++shiftCount[key]);
            }
        }
        return maxOverlap;
    }
};