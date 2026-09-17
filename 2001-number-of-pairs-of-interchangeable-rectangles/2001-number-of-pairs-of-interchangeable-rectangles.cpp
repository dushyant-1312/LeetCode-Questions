class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,long long> mapp;
        long long count = 0;

        for(auto it : rectangles){
            if(mapp.find((double)it[0]/it[1]) != mapp.end()){
                count += mapp[(double)it[0]/it[1]];
            }
            mapp[(double)it[0]/it[1]]++;
        } 
        return count;
    }
};