class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mapp;
        for(int i=0; i<nums.size(); i++) mapp[nums[i]].push_back(i);
    
        int count = 0;
        for(auto it : mapp){
            if(it.second.size() > 2){
                bool mark = true;
                for(int i=1; i<it.second.size(); i++) if(it.second[i] - it.second[i-1]  != (it.second[1] - it.second[0])) mark = false;
                if(mark) count++; 
            }
        }
        return count;
    }
};