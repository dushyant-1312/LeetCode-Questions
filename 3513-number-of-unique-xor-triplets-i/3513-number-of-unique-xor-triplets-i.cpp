class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int ans = 0;
        for(auto it : nums) ans |= it;
        return ans+1;
    }
};