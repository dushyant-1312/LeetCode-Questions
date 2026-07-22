class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> nums;
        for(auto it : grid){ for(auto i : it ) nums.push_back(i);}

        int n = nums.size();
        k = k%n;
        int y = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(k != 0){
                    grid[i][j] = nums[n-k];
                    k--;
                }
                else { grid[i][j] = nums[y++];}
            }
        }
        return grid;
    }
};