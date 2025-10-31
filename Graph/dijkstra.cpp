// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// same idea as prims algorithm
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<array<int,2>>>adj(V);
        for(auto &i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<bool>visited(V);
        priority_queue<array<int,2>>pq;
        pq.push({0,src});
        vector<int>ans(V);
        while(!pq.empty()){
            int w = -pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            
            if(visited[node]) continue;
            visited[node] = true;
            ans[node] = w;
            
            for(auto i:adj[node]){
                if(visited[i[0]]) continue;
                pq.push({-(i[1] +w),i[0]});
            }
        }
        return ans;
    }
};
