class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        if(s.size()==0) return 0;
        int j = 0 , i = 0;
        int contentChildren = 0;
        while(j<s.size() && i<g.size()){
            if(s[j]>=g[i]){
                i++;
                contentChildren++;
            }
            else{
                while((j<s.size()) && (s[j]<g[i]) ) j++;
                if(j<s.size()) {
                    i++;
                    contentChildren++;
                }
            }
            j++;
        }
        return contentChildren;
    }
};