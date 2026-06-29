class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);

        while(!pq.empty() && k != 0){
            auto it =  pq.top(); pq.pop();
            if(mul > 0){
                ans += (long long) mul * it;
            }
            else ans += it;
            k--; mul--;
        }
        return ans;
    }
};