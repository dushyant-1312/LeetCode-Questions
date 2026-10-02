class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mapp;
        unordered_map<int, int> mapp2;
        for(int i=0; i<nums.size(); i++){
            mapp2[nums[i]]++;
            mapp[nums[i]].push_back(i);
        } 


        int count = 0;
        for(auto it : mapp){
            if(mapp2[it.first] > 2){
                vector<int> t = it.second;
                int gap = t[1] - t[0];
                bool mark = true;
                for(int i=1; i<t.size(); i++){
                    if(t[i] - t[i-1]  != gap) mark = false;
                } 
                if(mark) count++; 
            }
        }
        return count;
    }
};