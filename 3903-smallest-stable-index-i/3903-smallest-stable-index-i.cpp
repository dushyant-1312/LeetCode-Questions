class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> pre(n, 0), sur(n, 0);

        pre[0] = nums[0];

        for(int i=1; i<n; i++){
            pre[i] = max(nums[i], pre[i-1]);
        }

        sur[n-1] = nums[n-1];

        for(int i=n-2; i >= 0; i--){
            sur[i] = min(nums[i], sur[i+1]);
        }
        for(int i=0; i<n; i++){
            cout<<pre[i]<<" ";
            cout<<sur[i]<<endl;
            if(pre[i] - sur[i] <= k) return i;
        }
        return -1;
    }
};