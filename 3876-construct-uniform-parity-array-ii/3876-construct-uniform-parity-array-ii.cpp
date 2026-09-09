class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int counte = 0; int counto = 0;
        int se = INT_MAX; int so = INT_MAX;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2 == 0){
                se = min(se, nums1[i]);
                counte++; 
            } 
            else {
                so = min(so, nums1[i]);
                counto++;  
            } 
        }
        if(!counto) return true;
        for(auto it : nums1){
            if(it % 2 == 0 && so > it) return false;
        }
        return true;
    }
};