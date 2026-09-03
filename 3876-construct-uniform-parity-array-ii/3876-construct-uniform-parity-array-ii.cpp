class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;
        bool odd = false , even =false;
        int evenMin = INT_MAX , oddMin = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(nums1[i] % 2 == 0){
                even = true;
                evenMin = min(evenMin , nums1[i]);
                
            }
            else{
               odd = true;
               oddMin = min(oddMin , nums1[i]);
            }

     
        }
        if(!odd || !even) return true;
        return oddMin < evenMin ;

    }
};