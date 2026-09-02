class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1) return true;
        bool even = false , odd = false;
        int count = 0;
        for(int num : nums1){
            if(odd && even) return true;
            if(num % 2 != 0){
                odd = true;
            }
            else {
                even = true;
            }
            count++;
        }
        if(odd && even) return true;
        if(odd && !even && count == nums1.size()) return true;
        if(even && !odd && count == nums1.size()) return true;
        
        return false;
    }
};