class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& marge) {
        // int n = nums.size();
        // vector<vector<int>> ans;

        // for(int i=0;i<n;i++){
        //     if(marge[1] < nums[i][0]){
        //         ans.push_back(marge);
        //         for(;i<n;i++){
        //             ans.push_back(nums[i]);
        //         }
        //         return ans;
        //     }
        //     else if(nums[i][1] < marge[0]){
        //         ans.push_back(nums[i]);
        //     }
        //     else{
        //         marge[0] = min(marge[0],nums[i][0]);
        //         marge[1] = max(marge[1],nums[i][1]);
        //     }
        // }
        // ans.push_back(marge);
        // return ans;
        nums.push_back(marge);
    int n = nums.size(); 
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || nums[i][0] > ans.back()[1]) {
            ans.push_back(nums[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
    }
};