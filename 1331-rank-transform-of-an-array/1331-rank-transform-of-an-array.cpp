class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans,nums;
        for(auto it : arr) nums.push_back(it);

        sort(nums.begin(),nums.end());
        int j = 1;
        unordered_map<int,int> mapp;
        for(int i=0; i<nums.size();  i++){
            if(mapp.find(nums[i]) == mapp.end())
            mapp[nums[i]] = j++;
        }

        for(auto it : arr){
            ans.push_back(mapp[it]);
        }

        return ans;
    }
};