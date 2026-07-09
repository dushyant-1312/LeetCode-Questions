// class Solution {
// public:
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
//         int nn = queries.size();
//         vector<bool> ans(nn, false);

//         for(int i=0; i<nn; i++){
//             int s = min(queries[i][0],queries[i][1]); int e = max(queries[i][0],queries[i][1]);
//             bool mark = true;
//             for(int i=s+1; i<=e; i++){
//                 if(abs(nums[i-1] - nums[i]) > maxDiff){
//                     mark = false; break;
//                 }
//             }
//             ans[i] = mark;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int len = nums.size();
        
        vector<int> prefix(len, 0);
        for (int i = 1; i < len; i++) {
            int is_invalid = abs(nums[i] - nums[i - 1]) > maxDiff ? 1 : 0;
            prefix[i] = prefix[i - 1] + is_invalid;
        }

        int nn = queries.size();
        vector<bool> ans(nn);

        for (int i = 0; i < nn; i++) {
            int s = min(queries[i][0], queries[i][1]);
            int e = max(queries[i][0], queries[i][1]);
            int count = prefix[e] - prefix[s];
            ans[i] = (count == 0);
        }
        
        return ans;
    }
};