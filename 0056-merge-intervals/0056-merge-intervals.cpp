class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        // if(nums.size() == 1) return nums;
        // vector<vector<int>> ans;

        // for(int i=0;i<nums.size()-1;i++){
        //     vector<int> x = nums[i];
        //     vector<int> y = nums[i+1];
        //     if(x[1] >= y[0]){
        //         ans.push_back({x[0],y[1]});      
        //     }
        //     else{
        //         ans.push_back(y);
        //     }
        // }
        // return ans;
        
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







    // int n = nums.size(); 
    // sort(nums.begin(), nums.end());

    // vector<vector<int>> ans;

    // for (int i = 0; i < n; i++) {
    //     if (ans.empty() || nums[i][0] > ans.back()[1]) {
    //         ans.push_back(nums[i]);
    //     }
    //     else {
    //         ans.back()[1] = max(ans.back()[1], nums[i][1]);
    //     }
    // }
    // return ans;