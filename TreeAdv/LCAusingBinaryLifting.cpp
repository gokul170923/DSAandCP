class BinaryLift{
public:
    int n,logn;
    vector<vector<int>>dp , prefix;
    vector<int>depth;
    BinaryLift(vector<vector<array<int,2>>>&adj,int n,int source){
        this->n = n;
        logn = (int)log2(n) + 1;
        dp.resize(n,vector<int>(logn,-1));
        prefix.resize(n,vector<int>(27,0));
        depth.resize(n,0);
        dfs(adj,source,-1,0);
    }

    void dfs(vector<vector<array<int,2>>>&adj,int node,int p,int d){
        dp[node][0] = p;
        depth[node] = d;
        for(int i=1;i<logn;i++){
            if(dp[node][i-1] == -1) continue;
            dp[node][i] = dp[dp[node][i-1]][i-1];
        }
        for(auto [i,s]:adj[node]){
            if(i==p) continue;
            prefix[i] = prefix[node];
            prefix[i][s]++;
            dfs(adj,i,node,d+1);
        }
    }

    int kthparent(int node,int k){
        for(int i = logn-1 ;i>=0;i--){
            if((k>>i)&1){
                if(dp[node][i] != -1) node = dp[node][i];
                else return -1;
            }
        }
        return node;
    }

    int LCA(int a,int b){
        if(depth[b] > depth[a]) b = kthparent(b,depth[b]-depth[a]);
        else if(depth[a] > depth[b]) a = kthparent(a,depth[a]-depth[b]);
        if(a==b) return a;
        for(int i = logn - 1;i>=0;i--){
            if(dp[a][i] == -1 || dp[b][i] == -1) continue;
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    }

    int find(int a,int b){
        int lca = LCA(a,b) , maxi = INT_MIN , sum = 0;
        for(int i=0;i<27;i++){
            int curr = prefix[a][i] + prefix[b][i] - 2 * prefix[lca][i];
            maxi = max(maxi,curr);
            sum += curr;
        }
        return sum - maxi;
    }
};
