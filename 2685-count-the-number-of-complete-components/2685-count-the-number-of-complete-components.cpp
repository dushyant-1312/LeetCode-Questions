class Solution {
public:
    void dfscheck(int node, vector<int> &vis, vector<int> graph[], int &countedge, int &countnode){
        vis[node] = 1;
        countnode++;
        for(auto it : graph[node]){
            countedge++;
            if(!vis[it]){
                dfscheck(it, vis, graph, countedge, countnode);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);

        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
            int countnode = 0; int countedge = 0;
                dfscheck(i, vis, graph, countedge, countnode);
                if(countedge == countnode * (countnode-1)) ans++;
            }
        }
        return ans;
    }
};