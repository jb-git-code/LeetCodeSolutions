class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for(char c: s){
            mpp[c]++;
        }
        vector<pair<char,int>> vec(mpp.begin() , mpp.end());

        sort(vec.begin() , vec.end()  ,[](const auto &a , const auto &b){
            return a.second > b.second;
        });

        string res ;
        for(auto v : vec){
            int freq = v.second;
            while(freq>0){
                res+= v.first;
                freq--;
            }
        }
        return res;
    }
};