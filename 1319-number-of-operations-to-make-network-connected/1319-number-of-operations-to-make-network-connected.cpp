class Solution {
public:
    void dfscheck(int node, vector<int>&vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfscheck(it, vis, graph);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        int edge = 0;
        if(connections.size() < n - 1) return -1;
        for(auto it: connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfscheck(i,vis,graph); count++; 
            }
        }
        return count - 1 ;
    }
};