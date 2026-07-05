class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9)); dist[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto it =  pq.top(); pq.pop();
            int dis = it[0]; int row = it[1]; int col = it[2];
            if(row == n-1 && col == m-1){
                if(dis < health) return true;
                else return false;
            }
            vector<pair<int,int>> nums = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int nrow = row + nums[i].first;
                int ncol = col + nums[i].second;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    if(dist[nrow][ncol] > dis + grid[nrow][ncol]){
                        dist[nrow][ncol] = dis + grid[nrow][ncol];
                        pq.push({dist[nrow][ncol], nrow, ncol});
                    }
                }
            }
        }
        return false;
    }
};