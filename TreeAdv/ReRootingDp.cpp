// Tree Distance I cses
// Tree Distance II cses
// https://codeforces.com/problemset/problem/1092/F

#include <bits/stdc++.h>
using namespace std;
                    
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl cout<<'\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(x) for(auto i:x) cout<<i<<' '
                    
const int mod = 1000000007;

void dfs1(vector<vector<int>>&adj,int node,int p,vector<array<int,2>>&dp){
        for(int i:adj[node]){
                if(i==p) continue;
                dfs1(adj,i,node,dp);
                int candidate = 1 + dp[i][0];
                if(candidate > dp[node][0]){
                        dp[node][1] = dp[node][0];
                        dp[node][0] = candidate;
                }
                else if(candidate > dp[node][1]){
                        dp[node][1] = candidate;
                }
        }
}

void dfs2(vector<vector<int>>&adj,int node,int p,vector<array<int,2>>&dp){
        if(p != -1){
                int candidate = 1 + dp[p][dp[p][0] == 1 + dp[node][0]];
                if(candidate > dp[node][0]){
                        dp[node][1] = dp[node][0];
                        dp[node][0] = candidate;
                }
                else if(candidate > dp[node][1]){
                        dp[node][1] = candidate;
                }
        }
        for(int i:adj[node]){
                if(i==p) continue;
                dfs2(adj,i,node,dp);
        }
}
                    
void solve(){
        int n;cin>>n;
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
                int u,v;cin>>u>>v;
                u--;v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        vector<array<int,2>>dp(n,{0,0});
        dfs1(adj,0,-1,dp);
        dfs2(adj,0,-1,dp);
        for(int i=0;i<n;i++){
                cout<<dp[i][0]<<' ';
        }
        nl;
}
                        
                        
int32_t main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       solve();
       return 0;
}
