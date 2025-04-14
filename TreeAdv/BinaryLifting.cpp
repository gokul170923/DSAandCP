class BinaryLift{
public:
        int n,logn;
        vector<vector<int>>dp;  
        
        BinaryLift(int n,vector<vector<int>>&adj,int source){
            this->n = n;
            logn = ceil(log2(n));
            dp.resize(n,vector<int>(logn,-1));
            dfs(adj,source,-1);
        }    

        void dfs(vector<vector<int>>&adj,int node,int p){
            dp[node][0] = p;
            for(int i=1;i<logn;i++){
                if(dp[node][i-1]==-1) break;
                dp[node][i] = dp[dp[node][i-1]][i-1];
            }
            for(int i:adj[node]){
                if(i==p) continue;
                dfs(adj,i,node);
            }
        }  

        int kthParent(int node,int k){
            for(int i=30;i>=0;i--){
                if((k>>i)&1){
                    if(i>=logn) return -1;
                    node = dp[node][i];
                }
                if(node==-1) break;
            }
            return node;
        }
};