class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> v;

        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            v.push_back(gcd(maxi, nums[i]));
        }
        sort(v.begin(), v.end());

        long long ans = 0;

        for(int i=0; i<nums.size()/2; i++){
            ans += gcd(v[i], v[nums.size()-1-i]);
        }
        return ans;
    }
};