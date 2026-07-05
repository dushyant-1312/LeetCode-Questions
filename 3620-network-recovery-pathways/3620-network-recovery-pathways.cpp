class Solution {
private:
    bool shortpath(int n, vector<pair<int,int>> graph[], vector<bool> &online, long long k, int &val){
        vector<long long> dist(n, 1e18); 
        dist[0] = 0;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            long long dis = it[0]; int pre = it[1]; 

            if(pre == n-1) return true;
            if(dis > dist[pre]) continue;
            
            for(auto i : graph[pre]){
                int sur = i.first; int newdis = i.second;
                if(dist[sur] > (long long)newdis + dis && (long long)newdis + dis <= k && online[sur] && newdis >= val){
                    dist[sur] = newdis + dis;  
                    pq.push({dist[sur], sur}); 
                } 
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(); 
        vector<pair<int,int>> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back({it[1],it[2]});
        }
        int s = 0; int e = 1e9; 
        int check = -1; 
        while(s <= e){
            int mid = s + (e-s)/2; 
            if(shortpath(n, graph, online, k, mid)){
                check = mid;
                s = mid + 1;
            }
            else e = mid-1;
        }
        return check;
    }
};