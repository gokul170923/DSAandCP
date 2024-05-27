#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll m = 1e9+7;

ll recc(int n){
    if(n==0) return 1LL;
    if(n<0) return 0LL;
    return recc(n-1)+recc(n-2)+recc(n-3)+recc(n-4)+recc(n-5)+recc(n-6);
}

ll memo(ll n,vector<ll>&dp){
    if(n<0) return 0;

    if(dp[n]) return dp[n];

    for(int i =1;i<=6;i++){
        dp[n] =(dp[n]+ memo(n-i,dp))%m;
    }
    return dp[n];
}

ll tabulate(int n,vector<ll>&dp){
    for(int i =0;i<n;i++){
        ll give = dp[i];
        for(int j =1;j<=6;j++){
            if(i+j<=n) dp[i+j] = (dp[i+j]+give)%m;
        }
    }
    return dp[n];
}

//space optimise with O(6)

void solve(){
    ll n;cin>>n;
    vector<ll>dp(n+1,0);
    dp[0] =1;

    cout<<tabulate(n,dp);
    
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}