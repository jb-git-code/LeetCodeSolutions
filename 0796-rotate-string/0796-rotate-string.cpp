class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            string rotated = "";

            for(int j = 0; j < n; j++) {
                rotated += s[(j + i) % n];
            }

            if(rotated == goal) return true;
        }

        return false;
    }
};