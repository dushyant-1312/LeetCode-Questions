class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int,int>> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>> dist(n, vector<int> (k+1, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,1}});
        dist[0][1] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it.first; int node = it.second.first; int count = it.second.second;
            if(dis > dist[node][count]) continue;
            if(node == n-1) return dis;
            
            for(auto it : graph[node]){
                int ncount = 1;
                if(labels[it.first] == labels[node]){
                    ncount = count+1;
                }
                if(ncount <= k && dist[it.first][ncount] > dis + it.second ){
                    dist[it.first][ncount] = dis + it.second;
                    pq.push({dist[it.first][ncount],{it.first,ncount}});
                }
            }
        }
        return -1;
    }
};