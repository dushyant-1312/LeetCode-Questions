class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mapp;
        for(int i=0; i<nums.size(); i++) mapp[nums[i]].push_back(i);

        int count = 0;
        for(auto it : mapp){
            if(it.second.size() == 3){
                bool mark = true;
                if(it.second[1] - it.second[0] != it.second[2] - it.second[1]) mark = false;
                if(mark) count++; 
            }
        }
        return count;
    }
};