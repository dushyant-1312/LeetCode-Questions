class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<pair<int,int>> ans;
        int mark = 0;
        for(auto it : nums){
            int i = it;
            int x = 0; int y = INT_MAX;
            while(it != 0){
                x = max(x, it%10);
                y = min(y, it%10);
                it /= 10;
            }
            ans.push_back({i, (x-y)});
            mark = max(mark, (x-y));
        }
        int sum = 0;
        for(auto it : ans) if(it.second == mark) sum += it.first;
        return sum;
    }
};