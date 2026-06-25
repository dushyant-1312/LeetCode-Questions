class Solution {
public:
    void dfscheck(int node, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]) dfscheck(it, vis, graph);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); int m = isConnected[0].size();
        vector<int> graph[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i != j && isConnected[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i, vis, graph); count++;
            }
        }
        return count;
    }
};