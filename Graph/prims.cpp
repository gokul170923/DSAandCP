// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
/*
  E logE + V log E
  (E + V) log E
  E log E
*/
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>>adj(V);
        for(auto &i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int ans = 0;
        vector<bool>visited(V);
        priority_queue<array<int,2>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int w = -pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            ans = ans + w;
            for(auto i:adj[node]){
                pq.push({-i[1],i[0]});
            }
        }
        return ans;
    }
};
