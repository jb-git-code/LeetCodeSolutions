class Solution {
public:
    int reverseDegree(string s) {
        int prod = 0 ;
        int a = 1;
        for(auto c : s){
            int rev = ('z' - c ) + 1;
            prod += rev*a;
            a++;
        }
        return prod;
    }
};